#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n;
ll m;
ll a[N];
ll cha[N];
struct shui{
	ll a;//水晶能量值 
	ll cnt;//水晶个数 
	ll cha;//与高一级水晶差多少
	ll id;//用来在cha中找和下一位差多少
	bool operator < (const shui &la) const
	{
		if (cha==la.cha)
		{
			return a>la.a;
		}
		return cha>la.cha;
	}
};
priority_queue<shui> jing;
ll erfen(ll l,ll r,ll id)//给差为cha.id升级 
{
	if  (l==r)
	{
		return l;
	}
	ll mid=(l+r)>>1;
	if (mid*cha[id]>=m)//用多了就少点 
	{
		return erfen(l,mid,id);
	}
	else
	{
		return erfen(mid+1,r,id);
	}
}
map<ll,ll> da;
int main()
{
	
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	//我要写特判了
	bool liu=1;
	ll jia=a[2]-a[1];
	for (ll i=1;i<n;i++)
	{
		if (a[i+1]-a[i]!=jia)
		{
			liu=0;
			break;
		}
	}
	if (liu)//是等差数列 
	{
		ll hao=0;
		if (((a[1]+a[n])*n/2)<=m)
		{
			cout<<n;
			return 0;
		}
		else
		{
			for (ll i=1;i<=n;i++)
			{
				if (m-jia*i>=0)
				{
					m-=jia*i;
					hao++;
				}
			}
		}
		cout<<hao;
		return 0;
	}
	//
	ll zuida=0;
	ll zuidaa=0;
	shui huo;
	ll ai;//水晶能量值 
	ll cnt=1;//水晶个数 
	//cha表示与高一级水晶差多少
	
	ll chac=0;
	
	
	for (ll i=1;i<=n;i++)
	{
		ai=a[i];
		if (ai==a[i+1])
		{
			cnt++;
		}
		else
		{
			huo.a=ai;
			huo.cnt=cnt;
			huo.id=++chac;
			if (huo.cnt>zuida)
			{
				zuida=huo.cnt;
				zuidaa=ai;
			}
			cha[chac]=a[i+1]-ai;
			if (i==n)
			{
				cha[chac]=1e18;
			}
			huo.cha=cha[chac];
			jing.push(huo);
			cnt=1;
		}
	}
	
	//huo复用 
	ll sheng=0;
	while (m)//升级忘改id
	{
		huo=jing.top();
		jing.pop();
		if (huo.cha*cnt<=m)//能全部升级 
		{
			m-=huo.cha*cnt;//消耗 
			huo.a+=cha[huo.id];//升级 
			huo.cha=cha[huo.id+1];//下一级需要 
			huo.id++;
			jing.push(huo);//升完了放回去 
		}
		else//二分找能升几个 
		{
			sheng=erfen(0,cnt,huo.id);
			//既然连最小的都不能全部升级，别干了！！ 
			m=0;
			huo.a+=cha[huo.id];
			huo.cha=cha[huo.id+1];
			huo.id++;
			huo.cnt=sheng;
			jing.push(huo);
		}
	}
	
	//huo复用
	ll ans=0;
	while (!jing.empty())//要找答案了，现在水晶全在jing
	{
		huo=jing.top();
		jing.pop();
		da[huo.id]+=huo.cnt;
		ans=max(ans,da[huo.id]);
	}
	cout<<ans;
	return 0;
}
/*

统计每两个数的差cha
如果小于m
m-cha;大数个数++;
优先找cha小的 
优先
优先队列!
但是要记住所有人差多少 
不对
你花那么多钱让后面的都往上
不如找一个让别的过来
如
5 5
1 2 4 4 6 10 10 10 10 10 10 10     -1
应该找到本来就最多的
然后让他后面的向他靠拢 
12 8
1 1 1 2 2 2 2 10 10 10 10 10 
不能总想着升级 
我要及时知道每个现在有几个
完啦完啦完啦
！
这次不得分我就不死了！！！ 
abababaabab
18：s29
只过了特盘 
*/
