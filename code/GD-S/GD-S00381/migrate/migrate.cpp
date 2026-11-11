#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T;
int n,d;
int x[N];
int pre[N],nxt[N];
int f[N][2],g[N],h[N];
int cnt[N];
int ans;
void solve(int l,int r)
{
	if(l==r)return ;
	int lst=l;
	for(int i=l;i<=r;i++)
	{
		while(x[i]-x[lst]>d)lst++;
		pre[i]=lst;
	}
	lst=r;
	for(int i=r;i>=l;i--)
	{
		while(x[lst]-x[i]>d)lst--;
		nxt[i]=lst;
	}
	for(int i=l;i<=r;i++)f[i][0]=f[i][1]=g[i]=h[i]=0;
	for(int i=l;i<=r;i++)
	{
		f[nxt[i]][0]++;
		if(nxt[i]-1!=i)
		{
			if(nxt[nxt[i]-1]==nxt[nxt[i]])f[nxt[i]-1][1]++,h[nxt[i]-1]++;
			else g[nxt[i]-1]++,h[nxt[i]-1]++;
		}
		
		if(i!=l)
		{
			if(nxt[pre[i]]==i)f[i][0]+=f[pre[i]][0],f[i][1]+=f[pre[i]][1];
			else if(nxt[pre[i]]==i+1&&nxt[i+1]==nxt[i])f[i][1]+=f[pre[i]][0],h[i]+=f[pre[i]][0];
			else if(nxt[pre[i]]==i+1)g[i]+=f[pre[i]][0],h[i]+=f[pre[i]][0];
		}
		if(i!=l)ans+=f[pre[i]][1]+g[pre[i]];
		if(i!=l&&pre[i]+1==i)ans-=h[pre[i]];
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int lst=1;
		for(int i=2;i<=n;i++)
		{
			if(x[i]-x[i-1]>d)
			{
				solve(lst,i-1);
				lst=i;
			}
		}
		solve(lst,n);
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
