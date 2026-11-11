#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i8 = __int128;
void sv();
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("migrate2.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
}
int main()
{
    fre();
    int C, T = 1; cin >> C >> T;
    //if (C)
        while (T--)
            sv();
    return 0;
}

const int NM = 2000100;
int a[NM], dlc[NM], dis[NM];//low distance count

void sv()
{
    memset(a, 0, sizeof(a));
    memset(dis, 0x3f, sizeof(dis));
    memset(dlc, 1, sizeof(dlc));
    int n, d, cnt = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        queue <int> q;
        memset(dis, 0x3f, sizeof(dis));
        dis[i] = 0;
        memset(dlc, 0, sizeof(dlc));
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int j = u+1; j <= n; j++)
            {
                if (a[j] - a[i] > d) break;
                if (dis[j] == dis[u]+1)
                    dlc[j]++;
                else if (dis[j] > dis[u]+1)
                {
                    dis[j] = dis[u]+1;
                    dlc[j] = 1;
                }
                //cout << j <<' '<< dis[j] <<' '<< dlc[j] <<'\n';
                q.push(j);
            }
        }
        for (auto x : dlc)
            if (x == 2) cnt++;
    }
    cout << cnt <<'\n';
}
