/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[514514],glj[505][505],f[505][505],b[505][505];
vector<pair<int,int> > gfake[1145140];
vector<pair<int,int> > line[514514];
vector<int> g[505];
void init()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<gfake[i].size();j++)
        {
            int u=gfake[i][j].first,w1=gfake[i][j].second;
            for(int k=0;k<gfake[i].size();k++)
            {
                if(k!=j)
                {
                    int v=gfake[i][k].first,w2=gfake[i][k].second;
                    f[u][v]=min(f[u][v],w1+w2);
                    f[v][u]=min(f[v][u],w1+w2);
                }
            }
            //这里可能还有用，留个空
            line[i].push_back({u,w1});
            //我是空
        }
    }
}
void dij(int step)
{
	priority_queue<pair<int,int> > q;
	f[step][step]=0;
	q.push({0,step});
	while(!q.empty())
	{
		while(!q.empty()&&b[step][q.top().second])
		q.pop();
		if(q.empty())
		break;
		int u=q.top().second;
		b[step][q.top().second]=1;
		for(int i=0;i<=g[u].size();i++)
		{
			int v=g[u][i];
			if(f[step][v]>f[step][u]+f[u][v])
			{
				f[step][v]=f[step][u]+f[u][v];
				q.push({-f[step][v],v});
			}
		}
	}
}
void fl()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            for(int k=1;k<=n;k++)
            {
                if(j!=k&&i!=k&&f[i][k]!=1e18&&f[k][j]!=1e18)
                {
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    //cout<<f[i][j]<<' '<<f[i][k]+f[k][j]<<endl;
                }
            }
        }
    }
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            glj[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)
    f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1,kk;i<=n;i++)
    {
        cin>>kk;
        for(int j=1,u,w;j<=kk;j++)
        {
            cin>>u>>w;
            gfake[u].push_back({i,w});
        }
    }
    init();
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i!=j&&f[i][j]!=1e18)
    		{
    			g[i].push_back(j);
			}
		}
	}
    
    //fl();
    for(int i=1;i<=n;i++)
    {
    	dij(i);
	}
    for(int t=1,x,y;t<=q;t++)
    {
        cin>>x>>y;
        //这里应该还会有个优化
        //好的不会了，d<=20
        int ans=1e18;
        //cout<<gfake[x].size()<<' '<<gfake[y].size()<<endl;
        for(int i=0;i<gfake[x].size();i++)
        {
            for(int j=0;j<gfake[y].size();j++)
            {
                int u=gfake[x][i].first,v=gfake[y][j].first;
                ans=min(ans,f[u][v]+gfake[x][i].second+gfake[y][j].second);
                //cout<<f[u][v]<<' '<<u<<' '<<v<<endl;
               // cout<<gfake[x][i].second<<' '<<gfake[y][j].second<<endl;
            }
        }
        cout<<ans+w[x]+w[y];
        puts("");
    }
    return 0;
}

/*
我们不难注意到 n 很小。
同时坐地铁的花费不与其里程相关。
所以，f[i][j] 表示 i 线到 j 线的换乘花费，而无论如何，只要你坐上了一个线路，你就一定能以 f_i_j 的代价换乘到 j 线
看到 q，大多数的选手都会想到离线处理。但如果成功利用 n 和 d，那么是不需要离线处理而可以在线的，所以我断定这是此题的区分点，所以这是本题的解法，这也与去年很像
*/
//我爱 VScode
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
//I AC it in 15:38
//i have 3h to solve T3!!!
//late 10min,but nothing
//��ע yulucangling&SokyuSitema&SokyuSistema(qid3853900329) лл���� 
