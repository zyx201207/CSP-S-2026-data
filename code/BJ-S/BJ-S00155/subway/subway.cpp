#include<bits/stdc++.h>
using namespace std;
int  p1[20005], p[20005][205], vis[20005], ed, ttc=INT_MAX, vip[205], n;
vector<int> sy[205];//p1:kou zhan p[x][y] xianlu y jiedian x sy:lu dian
void dfs(int u, int ph, int cost)//u dangqianjiedian ph lu
{
    vis[u]=1;
    vip[ph]=1;
    bool ok=0;
    //if (ph==2)
        //cout << cost <<'\n';
    for (int i:sy[ph])
    {
        //if (ph==2 && i==3)
        //cout << "WODAOLE";
        //cout << i <<' ';
        if (i==ed)
        {
            ttc=min(ttc, cost+p[i][ph]);
            return;
        }
        if (!vis[i])
        {
            for (int op=1;op<=n;op++)
            {
                if (op==ph)
                    continue;
                for (int j:sy[op])
                if (j==i&& !vip[op])
                {
                    dfs(i, op, p[i][ph]+p[i][op]+cost);
                    ok=1;
                    vis[i]=0;
                    vip[op]=0;
                }
            }
        }
    }
    if (ok=0)
        return;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> p1[i];
    for (int i=1;i<=n;i++)
    {
        int h;
        cin >> h;
        for (int k=1;k<=h;k++)
        {
            int l, pt;//dian lenth
            cin >> l >> pt;
            sy[i].push_back(l);
            p[l][i]=pt;
        }
    }
    //cout << p[1][1]  << ' ';
    //cout << g[1];
    while(q--)
    {
        ttc=INT_MAX;
        memset(vip, 0, sizeof(vip));
        memset(vis, 0, sizeof(vis));
        int st;
        cin >> st >> ed;
        int tot=p1[st]+p1[ed];
        for (int op=1;op<=n;op++)
        {
            for (int j:sy[op])
            if (j==st)
            {
                //cout << p[st][op] <<'\n';
                dfs(st, op, p[st][op]);
            }
        }
        //cout << tot << '\n';
        //cout << ttc;
        cout << ttc+tot <<'\n';
    }
    return 0;
}
