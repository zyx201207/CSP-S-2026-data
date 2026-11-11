#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
const int N = 506;
const int M = 500006;
const int D = 26;
int c,n,m,d,T,x,y,ans,k;
int w[M];
bool vis[M];
vector<int>b[N];
int a[M][D];
int cnt[M];
class kwsz666
{
public:
	int n,val;
};
vector<kwsz666>t[M];
class node
{
public:
	int now,num,sit;
};
int find(int h,int b)
{
	for(int i=0;i<t[h].size();i++)
	{
		if(t[h][i].n==b)return t[h][i].val;
	}
	return 0;
}
void solve()
{
	ans+=w[x],ans+=w[y];
	queue<node>q;
	memset(vis,0,sizeof(vis));
	node first;
	first.now=x;
	first.num=ans;
	first.sit=0;
	q.push(first);
	vis[x]=1;
	ans=1e16;
	while(!q.empty())
	{
		node tmp=q.front();
		int now=tmp.now;
		//cout<<now<<"\n";
		int sit=tmp.sit;
		int num=tmp.num;
		q.pop();
		if(now==y)
		{
			ans=min(ans,num);
			continue; 
		}
		if(sit==0)
		{
			if(cnt[now]==0)continue;
			for(int i=1;i<=cnt[now];i++)
			{
				node jkl;
				jkl.num=num+find(now,a[now][i]);
				jkl.sit=a[now][i];
				jkl.now=114514;
				q.push(jkl);
			}
		}
		else
		{
			for(int i=0;i<b[sit].size();i++)
			{
				if(!vis[b[sit][i]])
				{
					vis[b[sit][i]]=1;
					node jkl;
					jkl.now=b[sit][i];
					jkl.num=num+find(b[sit][i],sit);
					jkl.sit=0;
					q.push(jkl);
				}
			}
		}
	}
	return;
}
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int n1,n2;cin>>n1>>n2;
			a[n1][++cnt[n1]]=i;
			b[i].push_back(n1);
			kwsz666 tmp;
			tmp.n=i;
			tmp.val=n2;
			t[n1].push_back(tmp);
		}
	}
	while(T--)
	{
		cin>>x>>y;
		ans=0;
		solve();
		cout<<ans<<"\n";
	}
} 
