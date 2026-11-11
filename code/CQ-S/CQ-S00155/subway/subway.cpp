#include<bits/stdc++.h>
#define debug puts("FUCK");
#define int long long
using namespace std;
const int N=1000010;
int n,m,c,d,qq,w[N],k[N];
map<int,int>t[N],a[N],vis[N];
struct node
{
	int s,v,w;
	bool operator > (const node &x) const
	{
		return w>x.w;
	}
};
priority_queue<node,vector<node>,greater<node> >q;
int bfs(int sub,int s,int e,int z)
{
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			vis[i][j]=0;
		}
	}
	q.push({sub,s,t[sub][z]});
	vis[sub][z]=1;
	int minn=0x3f3f3f3f;
	while(!q.empty())
	{
//		debug
		node w=q.top();
//		cout<<w.s<<' '<<w.v<<' '<<w.w<<'\n';
		q.pop();
		if(w.v==e)
		{
			minn=min(minn,w.w);
			return minn;
		}
		for(int ll=1;ll<=k[w.s];ll++)
		{
//			debug
			int v=a[w.s][ll];
			if(vis[w.s][ll]==0)
			{
//				cout<<w.s<<' '<<ll<<' '<<a[w.s][ll]<<' '<<w.w<<' '<<t[w.s][ll]<<'\n';
				
				vis[w.s][ll]=1;
				q.push(node{w.s,a[w.s][ll],w.w+t[w.s][ll]});
			}
			for(int i=1;i<=n;i++)
			{
				if(i==w.s) continue;
				for(int pp=1;pp<=k[i];pp++)
				{
					if(a[i][pp]==v&&vis[i][pp]==0)
					{
//						cout<<"    "<<i<<' '<<pp<<' '<<a[i][pp]<<' '<<w.w<<' '<<t[i][pp]<<' '<<t[w.s][ll]<<'\n'; 
						vis[i][pp]=1;
						q.push(node{i,v,w.w+t[i][pp]+t[w.s][ll]});
					}
				}
			}
		}
	}
	return minn;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("txt.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			int tmp;
			cin>>tmp;
			if(j&1) a[i][(j+1)/2]=tmp;
			else t[i][(j+1)/2]=tmp;
		}
	}
	for(int i=1;i<=qq;i++)
	{
		int x,y,ans;
		cin>>x>>y;
		ans= 0x3f3f3f3f;
		for(int j=1;j<=n;j++)
		{
//			debug
			for(int z=1;z<=k[j];z++)
			{
//				cout<<a[j][z]<<'\n';
				if(a[j][z]==x)
				{
//					cout<<j<<' '<<z<<'\n';
//					cout<<ans<<'\n';
					ans=min(bfs(j,x,y,z),ans);
//					cout<<ans<<'\n';
				}
			}
		}
//		cout<<ans<<'\n';
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
