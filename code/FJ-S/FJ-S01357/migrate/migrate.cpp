#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace sol
{
	ll a[2000010],f[2000010][2];
	int nxt[2000010],flag[2000010],deg[2000010];
	int c[2000010][2];
	void solve()
	{
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)nxt[i]=flag[i]=deg[i]=c[i][0]=c[i][1];
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0ll;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=4e18;
		int pt=1;
		for(int i=2;i<=n+1;i++)
			while(a[pt]+d<a[i])nxt[pt++]=i-1;
		for(int i=1;i<=n;i++)
		{
			if(i-1>0&&a[i-1]+d>=a[nxt[i]])
			{
				flag[i]++;
				if(i-2>0&&a[i-2]+d>=a[nxt[i]])flag[i]++;
			}
		}
		pt=n;
		for(int i=n-1;i>=2;i--)
		{
			while(a[i-1]+d<a[pt])pt--;
			c[i][0]=max(nxt[i]-max(pt,i),0);
		}
		pt=n;
		for(int i=n-1;i>=3;i--)
		{
			while(a[i-2]+d<a[pt])pt--;
			c[i][1]=max(nxt[i-1]-max(pt,i),0);
//			cout<<"dq:"<<i<<" "<<nxt[i-1]<<" "<<pt<<'\n';
		}
		for(int i=1;i<n;i++)deg[nxt[i]]++;
		queue<int>q;
		for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(nxt[u]==u)continue;
			deg[nxt[u]]--;
			if(!deg[nxt[u]])q.push(nxt[u]);
			if(flag[u]==2)f[nxt[u]][0]++;
			if(flag[u]==1)f[nxt[u]][0]++,f[nxt[u]][1]+=f[u][0];
			if(flag[u]==0)f[nxt[u]][0]+=f[u][0]+1,f[nxt[u]][1]+=f[u][1];
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=f[i][0]*c[i][1]+f[i][1]*c[i][0];
		cout<<ans<<'\n';
//		cout<<"nxt:";for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";cout<<'\n';
//		cout<<"flag:";for(int i=1;i<=n;i++)cout<<flag[i]<<" ";cout<<'\n';
//		cout<<"f:\n";for(int i=1;i<=n;i++)cout<<f[i][0]<<" "<<f[i][1]<<'\n';
//		cout<<"f0:\n";for(int i=1;i<=n;i++)cout<<f0[i]<<" ";cout<<'\n';
//		cout<<"c:\n";for(int i=1;i<=n;i++)cout<<c[i][0]<<" "<<c[i][1]<<'\n';
	}
	int main()
	{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int c,t;
		cin>>c>>t;
		while(t--)solve();
		return 0;
	}
}
int main()
{
	sol::main();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
