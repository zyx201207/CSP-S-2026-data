#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<pair<int, int> > G[N];
int w[N];

int c, n, m, d, q;

int s[N];
bool vis[N];
void dijkstra(int k, int n)
{
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
    for(int i = 1; i <= n; i++)
    {
        s[i] = 0x3f3f3f3f;
        vis[i] = 0;
    }
    s[k] = 0;
    q.push({0, k});
    while(!q.empty())
    {
        int w = q.top().first, u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : G[u])
        {
            if(!vis[v.first])
            {
                if(s[v.first] > s[u] + v.second)
                {
                    s[v.first] = s[u] + v.second;
                }
                q.push({s[v.first], v.first});
                
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);//dont forget
    freopen("subway.out", "w", stdout);//dont forget
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    int cnt = m;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        cnt++;
        while(k--)
        {
            int a, t;
            cin >> a >> t;
            G[a].push_back({cnt, t});
            G[cnt].push_back({a, t});
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        dijkstra(x, cnt);
        cout << s[y] + w[x] + w[y] << endl;
    }
    return 0;
}
 
//---
//wowaka & hitorie collection Pt. 2
//*Fuyuno*
//---