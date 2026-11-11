#include <bits/stdc++.h>
#define int long long

using namespace std;

int c,n,m,d,q;
int w[300010];
vector<pair<int,int> > way[300010];
pair<int,int> road[300010];
int start,dest;
int minn;
int f[300010];

void reset()
{
    for(int i = 1;i <= m;i++)
        f[i] = LLONG_MAX / 2;
    minn = LLONG_MAX;
}

void dfs(int now,int used)//used = used time
{
    if(f[now] < used) return;
    if(used > minn) return;
    if(now == dest)
    {
        minn = min(minn,used);
        return;
    }

    //normal node
    f[now] = used;
    for(int i = 0;i < way[now].size();i++)
    {
        dfs(way[now][i].first,used + way[now][i].second);
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i++) cin >> w[i];

        //dfs!
        for(int i = 1;i <= n;i++)
        {
            int k;
            cin >> k;
            for(int j = 1;j <= k;j++)
            {
                cin >> road[j].first >> road[j].second;
            }
            //build a map
            for(int j = 1;j <= k;j++)
            {
                for(int jj = 1;jj <= k;jj++)
                {
                    if(j == jj) continue;
                    int from = road[j].first;
                    int to = road[jj].first;
                    int road_time = road[j].second + road[jj].second;
                    way[from].push_back(make_pair(to,road_time));
                }
            }
        }

        //the map is done
        //now, for every question, use dfs to find the way, plus w

        for(int i = 1;i <= q;i++)
        {
            reset();
            cin >> start >> dest;
            dfs(start,0);
            cout << minn + w[start] + w[dest] << endl;
        }


    return 0;
}
