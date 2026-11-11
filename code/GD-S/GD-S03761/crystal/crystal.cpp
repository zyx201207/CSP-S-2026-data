#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
ll n,m;
ll a[200005],c[200005];
vector<ll> sub[200005];
ll xb;
map<ll,ll> mp;
bool spe1=1;//特殊性质1：a[i]=i
bool spe2=1;//特殊性质2：输入构成等差数列 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	//0. 输入 + 计重 + 排序（map已经排好序了） 
	ll last1=0,last2=0,last3=0;
	for(ll i=1;i<=n;i++)
	{
		ll temp;
		cin>>temp;
		mp[temp]++;
		
		if(temp!=i)
		{
			spe1=0;
		}
		if(i>=3&&((last3-last2)!=(last2-last1)))
////		32	33	D:\GD-S03761\crystal\crystal.cpp	
////		[Warning] 'last3' may be used uninitialized [-Wmaybe-uninitialized]
////		不会的，因为之前判了i>=3   
		{
			spe2=0;
		}
		
		last3=last2;
		last2=last1;
		temp=last1;
	}
	for(auto i:mp)
	{
		a[++xb]=i.first;
		c[xb]=i.second;
	}
	//1. 处理特殊性质1 
	if(spe1)
	{
		ll ans=0;
		ans=c[xb];
		for(ll i=xb-1;i>=1;i--)
		{
			if(m>(a[xb]-a[i])*c[i]&&i!=1)
			{
				ans+=c[i];
				m-=(a[xb]-a[i])*c[i];
			}
			else
			{
				while(m>=0)
				{
					if(m>=a[xb]-a[i])
					{
						ans++;
						c[i]--;
						m-=(a[xb]-a[i]);
					}
					else
					{
						break;
					}
				}
				cout<<ans<<'\n';
				break;
			}
//			ans+=a[xb]-a[i];
			
		}
		return 0; 
	}
	//2. 处理特殊性质2 
	else if(spe2)
	{
		//因为之前map已排序所以不用再跑一遍sort 
		ll ans=0;
		ans=c[xb];
		for(ll i=xb-1;i>=1;i--)
		{
			if(m>(a[xb]-a[i])*c[i]&&i!=1)
			{
				ans+=c[i];
				m-=(a[xb]-a[i])*c[i];
			}
			else
			{
				while(m>=0)
				{
					if(m>=a[xb]-a[i])
					{
						ans++;
						c[i]--;
						m-=(a[xb]-a[i]);
					}
					else
					{
						break;
					}
				}
				cout<<ans<<'\n';
				break;
			}
//			ans+=a[xb]-a[i];
			
		}
		return 0; 
	}
    //3. 处理前45分
	else
	{
//		//3.1. 预处理统计
		//对于每个节点，~~由前往后遍历前面的节点 ~~
		//位置相差大于等于2的节点可以由前一个节点得到（不过还是要搞一遍sub也是一样的啦）
		
		//3.1. 搞 
		ll ans=c[1];
		for(ll i=2;i<=xb;i++)
		{
			//我们要枚举以哪个节点开始能够更经济，因此我们需要每个节点都重新算一遍
			ll now=a[i];
			ll ncnt=c[i];
			ll nans=ncnt;
			ll mm=m;
			for(ll j=i-1;j>=1;j--)
			{
				//对于往前走的每个节点，每个都计数
				if(mm>=(now-a[j])*c[j]&&(j!=1))
				{
					nans+=c[j];
					mm-=(now-a[j])*c[j];
					ans=max(ans,nans);
				}
				else
				{
					while(mm>=0&&c[j]>0)
					{
						if(mm>=now-a[j])
						{
							nans++;
							c[j]--;
							mm-=(now-a[j]);
						}
						else
						{
							break;
						}
					}
					ans=max(ans,nans);
				}
				
			}
		}
		cout<<ans<<'\n';
	} 
	
	return 0;
} 
