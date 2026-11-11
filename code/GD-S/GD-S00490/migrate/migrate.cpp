#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,T,n,d,a[N];
ll dis[N],w[N];
ll subA()//8pts
{
	if(n<=2) return 0;
	ll cha=a[2]-a[1];
	if(cha>d) return 0;
	if(cha*2>d) return 0;
	ll jump=d/cha;
	ll jian=2*jump-1;
	ll res=n-jian;
	//cout<<n<<" "<<d<<" "<<cha<<" "<<a[2]<<" "<<a[1]<<endl;
	return max(res,0ll);
}
void Dijkstra(ll start)
{
	queue<ll> q;
	for(int i=start;i<=n;i++)
	{
		dis[i]=1e18;
		w[i]=0;
	}
	dis[start]=0;
	w[start]=1;
	q.push(start);
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		ll you=upper_bound(a+start,a+n+1,a[u]+d)-a;
		you--;
		//cout<<u<<" "<<you<<endl;
		if(you<=u) continue;
		for(int i=u+1;i<=you;i++)
		{
			if(dis[i]==1e18)
			{
				dis[i]=dis[u]+1;
				w[i]=w[u];
				q.push(i);
			}
			else
			{
				if(dis[u]+1==dis[i]) w[i]+=w[u];
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12)
		{
			printf("%lld\n",subA());
			continue;
		}
		//brute:40pts
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			Dijkstra(i);
			//cout<<i<<"\n";
			for(int j=i+1;j<=n;j++)
			{
				if(dis[j]!=1e18&&w[j]==2) ans++;
				//cout<<j<<" "<<dis[j]<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
