#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(i) cout<<"Debug "<<i<<' '
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define sc second
const int N=2e6+10;
int C,T,n,k;
int tot,head[N],to[N],nxt[N],dis[N];
inline void add(int a,int b)
{
	tot++;
	to[tot]=b;nxt[tot]=head[a];head[a]=tot;
}
inline void sol()
{
	cin>>n>>k;tot=0;memset(head,0,sizeof(head));
	for(int i=1,a,b;i<n;i++) cin>>a>>b,add(a,b),add(b,a);
	int ans=0x3f3f3f3f;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)!=k) continue;
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if((i>>(j-1)&1)==0) continue;
			for(int l=head[j];l;l=nxt[l])
			{
				int t=to[l];
				if(i>>(t-1)&1) sum++;
			}
		}
		if(k-sum>2) continue;
		memset(dis,0x3f,sizeof(dis));
		queue<int>q;
		for(int j=1;j<=n;j++) if(i>>(j-1)&1) q.push(j),dis[j]=0;
		int x=0;
		while(!q.empty())
		{
			int p=q.front();q.pop();x=max(x,dis[p]);
			for(int i=head[p];i;i=nxt[i])
			{
				int t=to[i];
				if(dis[t]>n) dis[t]=dis[p]+1,q.push(t); 
			}
		}
		ans=min(ans,x);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--) sol();
 }

