#include<iostream>
#include<vector>
#include<queue> 
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int c,n,m,d,q;
int k,x,y;
int f[500512],b[500012],ans[500012],s[500512];
struct lmr
{
	int l,r,id;
}wen[500012];
bool cmp(lmr x,lmr y)
{
	return x.l<y.l;
}
struct wcc
{
	int lie,num;
};
struct hjj
{
	int lie,num;
	bool operator <(hjj x)const 
	{
		return x.num<num;
	}
};
vector<wcc>a[500512];
priority_queue<hjj>lqq;
void dfs(int x)
{
	for(int i=1;i<=m+n;i++)f[i]=1e18;
	for(int i=1;i<=m+n;i++)s[i]=0;
	f[x]=0;
	lqq.push((hjj){x,f[x]});
	while(!lqq.empty())
	{
		int u=lqq.top().lie;
		lqq.pop();
		if(s[u]==1)continue;
		s[u]=1;
		for(int i=0;i<a[u].size();i++)
		{
			int v=a[u][i].lie;
			int num=a[u][i].num;
			if(s[v])continue;
			if(f[v]>f[u]+num)
			{
				f[v]=f[u]+num;
				lqq.push((hjj){v,f[v]});
			}
		}
	}
} 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x].push_back((wcc){m+i,y});
			a[m+i].push_back((wcc){x,y});
		}
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x>y)swap(x,y);
		wen[i].id=i;
		wen[i].l=x;
		wen[i].r=y;
	}
	sort(wen+1,wen+1+q,cmp);
	for(int i=1;i<=q;)
	{
		dfs(wen[i].l);
		for(int j=0;j<=q;j++)
		{
			if(wen[i+j].l!=wen[i].l)
			{
				i+=j;
				break;
			}
			ans[wen[i+j].id]=f[wen[i+j].r]+b[wen[i+j].l]+b[wen[i+j].r];
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
}
