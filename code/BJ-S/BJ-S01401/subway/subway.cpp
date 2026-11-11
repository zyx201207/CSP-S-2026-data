#include<bits/stdc++.h>
//#define int long long
using namespace std;

int c,n,m,d,q;
int w[500010];
int k[500010];
long long dis[510][510];

struct Node
{
    int v;
    long long w;
    bool operator <(const Node &nd)const
    {
        return this -> w > nd.w;
    }
};

vector<Node> s[500010];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            int a,t;
            cin >> a >> t;
            s[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < s[i].size();j++)
        {
            for(int k = 0;k < s[i].size();k++)
            {
                dis[s[i][k].v][s[i][j].v] = dis[s[i][j].v][s[i][k].v] = s[i][j].w + s[i][k].w;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        dis[i][i] = 0;
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            if(i != k && dis[i][k] != dis[0][0])
            {
                for(int j = 1;j <= n;j++)
                {
                    if(j != k && j != i && dis[k][j] != dis[0][0])
                    {
                        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                        dis[j][i] = dis[i][j];
                    }
                }
            }
        }
    }
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        cin >> x >> y;
        long long sum = 1LL << 62;
        for(int j = 0;j < s[x].size();j++)
        {
            for(int k = 0;k < s[y].size();k++)
            {
                sum = min(sum,dis[s[x][j].v][s[y][k].v] + s[x][j].w + s[y][k].w);
            }
        }
        cout << sum + w[x] + w[y] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
