#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
    int k;
    int a[20005];
    int t[20005];
};

struct Node2
{
    int pos;
    int cost;
};

Node l[505];
int time_io[500005];
int b[20005];
int bb[20005][25];
int bb_time[20005][25];
int dis_line[505][505];
int temp_dis_line[505][505];
int c, n, m, d, q;
queue<Node2> que;

void bfs(int st)
{
    while (!que.empty())
    {
        que.pop();
    }
    que.push({st, 0});
    while (!que.empty())
    {
        Node2 fr = que.front();
        que.pop();
        cout << fr.pos << " " << fr.cost << endl;
        for (int i = 1; i <= l[fr.pos].k; i++)
        {
            for (int j = 1; j <= b[l[fr.pos].a[i]]; j++)
            {
                if (bb[l[fr.pos].a[i]][j] == fr.pos)
                {
                    continue;
                }
                if (fr.cost + l[fr.pos].t[i] + bb_time[l[fr.pos].a[i]][j] < dis_line[st][bb[l[fr.pos].a[i]][j]])
                {
                    dis_line[st][bb[l[fr.pos].a[i]][j]] = fr.cost + l[fr.pos].t[i] + bb_time[l[fr.pos].a[i]][j];
                    dis_line[bb[l[fr.pos].a[i]][j]][st] = fr.cost + l[fr.pos].t[i] + bb_time[l[fr.pos].a[i]][j];
                    que.push({bb[l[fr.pos].a[i]][j], fr.cost + l[fr.pos].t[i] + bb_time[l[fr.pos].a[i]][j]});
                }
            }
        }
    }
    return;
}


int main()
{
    cin >> c;
    cin >> n;
    cin >> m;
    cin >> d;
    cin >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> time_io[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i].k;
        for (int j = 1; j <= l[i].k; j++)
        {
            cin >> l[i].a[j];
            cin >> l[i].t[j];
            b[l[i].a[j]]++;
            bb[l[i].a[j]][b[l[i].a[j]]] = i;
            bb_time[l[i].a[j]][b[l[i].a[j]]] = l[i].t[j];
        }
    }

    memset(dis_line, 999999, sizeof(dis_line));
    for (int i = 1; i <= n; i++)
    {
        dis_line[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    while (q--)
    {
        int x, y;
        cin >> x;
        cin >> y;
        int ans = 1e9;
        for (int i = 1; i <= b[x]; i++)
        {
            for (int j = 1; j <= b[y]; j++)
            {
                int temp_time = dis_line[bb[x][i]][bb[y][j]] + bb_time[x][i] + bb_time[y][j] + time_io[x] + time_io[y];
                ans = min(ans, temp_time);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
