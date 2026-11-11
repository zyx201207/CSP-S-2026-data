#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+100;
struct Node
{
    int ln,lt;
};
int st[N];
vector<Node> t[N];
int l[550][550];
int c,n,m,d,q;
//===========================================
void build()
{
    for(int k = 1;k <= m;k++)
    {
        if(t[k].size() > 1)
        {
            for(int i = 0;i < t[k].size()-1;i++)
            {
                for(int j = i+1;j < t[k].size();j++)
                    l[t[k][i].ln][t[k][j].ln] = l[t[k][j].ln][t[k][i].ln] = min(l[t[k][i].ln][t[k][j].ln],
                                                    t[k][i].lt+t[k][j].lt);
            }
        }
    }
    for(int i = 1;i <= n;i++)
        l[i][i] = 0;
    /*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            cout << 'i' << i << 'j' << j << ' ' << l[i][j] << '&' << l[j][i] << "    ";
        cout << endl;
    }
    */
    return;
}
//===========================================
void ans()
{
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                l[i][j] = l[j][i] = min(l[i][j],l[i][k]+l[k][j]);
    //cout << "=======================\n";
    /*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
            cout << 'i' << i << 'j' << j << ' ' << l[i][j] << '&' << l[j][i] << "    ";
        cout << endl;
    }
    */
    return;
}
void solve()
{
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        cin >> x >> y;
        int ans = 0x3f3f3f3f;
        if(!(c >= 12 && c <= 19))
        {
            for(int i = 0;i < t[x].size();i++)
                for(int j = 0;j < t[y].size();j++)
                    ans = min(ans,
                            t[x][i].lt+l[t[x][i].ln][t[y][j].ln]+t[y][j].lt);
            cout << ans+st[x]+st[y] << endl;
        }
        else
        {
            for(int i = 0;i < t[x].size();i++)
                for(int j = 0;j < t[y].size();j++)
                    ans = min(ans,
                              l[t[x][i].ln][t[y][j].ln]);
            cout << ans+st[x]+st[y]+2*t[x][0].lt;
        }
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(l,0x3f3f3f3f,sizeof l);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> st[i];
    for(int i = 1;i <= n;i++)
    {
        int ls;
        cin >> ls;
        for(int j = 1;j <= ls;j++)
        {
            int sn,lt;
            cin >> sn >> lt;
            t[sn].push_back({i,lt});
        }
    }
    build();
    ans();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
