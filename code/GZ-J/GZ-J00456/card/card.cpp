//GZ-J00456
//贵阳市白云区华师一学校 
//廖博亚 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+5;
ll st=1,ed=0;
ll v[N];
ll a[N],flag[N],res[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll stt=1;stt<=n;stt++)
	{	
		for(ll i=stt;i<=n;i++)
		{
			if(flag[a[i]]!=0)
			{
				while(v[ed]!=a[i]&&ed>=st)
				{
					flag[v[ed]]=0;
					ed--;
				}
			} 
			else
			{
				ed++;
				flag[a[i]]=1;
				v[ed]=a[i];
			}
		}
		for(ll i=st;i<=ed;i++) res[v[i]]++;
		while(ed>=st)
		{
			flag[v[ed]]=0;
			ed--;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<res[i]<<" ";
	}
}
