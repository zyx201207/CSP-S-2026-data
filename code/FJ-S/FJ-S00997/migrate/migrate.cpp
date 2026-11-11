#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+5;
int n,mn[N],mx[N<<2],tag1[N<<2],tag2[N<<2],c,T,D[N],vis[N];
vector<int>v[N];
ll d,x[N],ans,cnt[N];
void pushadd(int x,int k){mx[x]+=k;tag1[x]+=k;return;}
void pushmark(int x,int k){mx[x]=k;tag2[x]=k;return;}
void pushdown(int x)
{
	if(tag2[x]!=-1)
	{
		pushmark(x<<1,tag2[x]);
		pushmark(x<<1|1,tag2[x]);
		tag2[x]=-1;
	}
	if(tag1[x])
	{
		pushadd(x<<1,tag1[x]);
		pushadd(x<<1|1,tag1[x]);
		tag1[x]=0;
	}
	return;
}
void update1(int rt,int l,int r,int a,int b,int k)
{
	if(a>b)return;
	if(a<=l&&r<=b){pushadd(rt,k);return;}
	pushdown(rt);
	int mid=l+r>>1;
	if(a<=mid)update1(rt<<1,l,mid,a,b,k);
	if(b>mid)update1(rt<<1|1,mid+1,r,a,b,k);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	return;
}
void update2(int rt,int l,int r,int a,int b,int k)
{
	if(a>b)return;
	if(a<=l&&r<=b){pushmark(rt,k);return;}
	pushdown(rt);
	int mid=l+r>>1;
	if(a<=mid)update2(rt<<1,l,mid,a,b,k);
	if(b>mid)update2(rt<<1|1,mid+1,r,a,b,k);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	return;
}
int query(int rt,int l,int r,int k)
{
	if(l==r)return l;
	pushdown(rt);
	int mid=l+r>>1;
	if(mx[rt<<1]>=k)return query(rt<<1,l,mid,k);
	else return query(rt<<1|1,mid+1,r,k);
}
void build(int rt,int l,int r)
{
	tag2[rt]=-1;mx[rt]=tag1[rt]=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	return; 
}
void debug(int rt,int l,int r)
{
	if(l==r){cout<<mx[rt]<<" ";return;}
	pushdown(rt);
	int mid=l+r>>1;
	debug(rt<<1,l,mid);debug(rt<<1|1,mid+1,r);
	return;
}
void bfs(int s)
{
	for(int i=1;i<=n;i++)D[i]=1e9,cnt[i]=0,vis[i]=0;
	D[s]=0;vis[s]=1;
	cnt[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int t:v[u])
			if(!vis[t])
			{
				D[t]=D[u]+1;
				vis[t]=1;
				cnt[t]=cnt[u];
				q.push(t);
			}
			else if(D[t]==D[u]+1)cnt[t]+=cnt[u];
	}
	for(int i=s+1;i<=n;i++)
		if(cnt[i]==2&&i!=s)ans++;
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		if(n<=5000)
		{
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(x[j]-x[i]<=d)v[i].push_back(j);
			for(int i=1;i<=n;i++)
				bfs(i);
			for(int i=1;i<=n;i++)v[i].clear();
			cout<<ans<<'\n';
			continue;
		}
		int cur=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			while(cur<i&&x[cur]+d<x[i])cur++;
			mn[i]=cur;
		}
		build(1,1,n);
		int j=1;ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int r=min(mn[i],query(1,1,n,3)),l=query(1,1,n,2);
			if(l<r)ans+=r-l;
			if(mn[i+1]==i+1){update2(1,1,n,1,i,0);continue;}
			int lasj=j;j=mn[i+1];
			for(;j<mn[i+1];j++)update1(1,1,n,mn[j],lasj-1,-1);
			update1(1,1,n,lasj,j-1,i-j);
			update1(1,1,n,mn[i],j-1,1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/
