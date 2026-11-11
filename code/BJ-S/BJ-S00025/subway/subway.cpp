#include<bits/stdc++.h>
using namespace std;
const int MAXM = 5 * 1e5 + 1;
struct Node{int a,t;};

int c, n, m, d, q;
int w[MAXM];
vector<int>G[MAXM];
vector<Node>E[501];

bool cmp(int a,int b){ return a > b;}

int bfs(int s,int t)
{
    int ans = w[s] + w[t], dij[MAXM];
    memset(dij,0,sizeof(dij));
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(0 * m + s);

    while(!pq.empty())
    {
        int u = pq.top() % m,dis = pq.top() / m;

        pq.pop();
        for(int i = 0; i < G[u].size();i++)
        {
            int k = G[u][i];
            int j = 0;
            for(;j < E[k].size() && E[k][j].a != u;j++);
            for(int v = j + 1;v < E[k].size();v++)
            {
                if(dij[E[k][v].a] != 0) continue;
                dij[E[k][v].a] = dis + E[k][j].t + E[k][v].t;
                if(E[k][v].a == t) return dij[E[k][v].a] + ans;
                else pq.push(dij[E[k][v].a] * m + E[k][v].a);


            }

        }

    }

}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(int i = 1;i <= m;i++) scanf("%d",&w[i]);

    for(int i = 1;i <= n ;i++)
    {
        int k;
        scanf("%d",&k);

        for(int j = 1;j <= k ;j++)
        {
            int a, t;
            scanf("%d %d",&a,&t);

            E[i].push_back({a,t});
            G[a].push_back(i);
        }

    }


    while(q--)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        printf("%d\n",bfs(u,v));
    }

    return 0;
}
