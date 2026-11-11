#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define f1 first
#define s2 second
ll c,t,n,d,x[2000005];
ll rd()
{
	ll ans=0,f=1;
	char c;
	do c=getchar();
	while(!isdigit(c)&&c!='-');
	if(c=='-')f=-1;
	else ans+=c-'0';
	while(1)
	{
		c=getchar();
		if(!isdigit(c))break;
		ans*=10;ans+=c-'0';
	}
	return ans*f;
}
int main()
{
#ifndef zhengyi
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	c=rd(),t=rd();
	while(t--)
	{
		n=rd(),d=rd();
		for(int i=1;i<=n;i++)x[i]=rd();
		if(c==11||c==12)
		{
			int s=x[2]-x[1],e=d/s;
			if(e==1)cout<<0<<"\n";
			else if(e==2)cout<<n-3<<"\n";
			else
			{
				cout<<0<<"\n";
			}
		}
		else
		{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				unordered_map<ll,ll> um;
				vector<bool> m2(n+5,0),m3(n+5,0);
				vector<ll> arr(n+5,0);
				queue<pii> q;
				q.push({i,0});
				while(q.size())
				{
					pii p=q.front();
					q.pop();
					ll now=p.f1,st=p.s2;
					if(m2[now])m3[now]=1;
					else if(++um[now]>2)um.erase(now),m2[now]=1;
					if(!m3[now])
						for(int j=now+1;j<=n&&abs(x[j]-x[now])<=d;j++)
						{
							if(!arr[j])arr[j]=st+1,q.push({j,st+1});
							else if(arr[j]==st+1)q.push({j,st+1});
						}
				}
				for(auto j:um)if(j.second==2)ans++;
			}
			cout<<ans<<"\n";
		}
			
	}
	return 0;
}

