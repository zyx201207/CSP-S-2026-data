#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int k[500005],a[505][500005],w[500005],t[505][500005],h[500005],hh[500005][21];
int c,n,m,d,q;
bool chli[505];
long long p[500005],pb[500005];
void build(int root)
{
    for(int i = 1;i <= h[root];i++)
    {
        int li = hh[root][i];
        if(chli[li] == 1) continue;
        int tm = 0;
        for(int j = 1;j <= k[li];j++)
        {
            int st = a[hh[root][i]][j];
            if(st == root)
            {
                tm = t[li][j];
                break;
            }
        }
        for(int j = 1;j <= k[li];j++)
        {
            int st = a[hh[root][i]][j];
            if(st != root)
            {
                if((tm + t[li][j] + p[root]) < pb[st])
                {
                    p[st] = tm + t[li][j] + p[root];
                    pb[st] = p[st];
                }
                   //p[st] = min(tm + t[li][j],pb[st]);
            }
        }
    }
    int che = m - 1;
    for(int i = 1;i <= m;i++)
    {
        if(p[i] > 0) che--;
    }
    if(che > 0)
    {
        for(int i = 1;i <= h[root];i++)
        {
            int li = hh[root][i];
            if(chli[li] == 1) continue;
            for(int j = 1;j <= k[hh[root][i]];j++)
            {
                int st = a[hh[root][i]][j];
                pb[st] = p[st];
                build(st);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            //cout << t[i][j] << endl;
            h[a[i][j]]++;
            hh[a[i][j]][h[a[i][j]]] = i;
        }
    }
    int x,y;
    long long ans = 0;
    for(int ii = 1;ii <= q;ii++)
    {
        ans = 0;
        memset(p,0,sizeof(p));
        memset(pb,2000000005,sizeof(pb));
        memset(chli,0,sizeof(chli));
        cin >> x >> y;
        ans = ans + w[x] + w[y];
        for(int i = 1;i <= h[x];i++)
        {
            int li = hh[x][i];
            chli[li] = 1;
            int tm = 0;
            for(int j = 1;j <= k[li];j++)
            {
                int st = a[hh[x][i]][j];
                if(st == x)
                {
                    tm = t[li][j];
                    break;
                }
            }
            for(int j = 1;j <= k[li];j++)
            {
                int st = a[hh[x][i]][j];
                if(st != x)
                {
                    if((tm + t[li][j]) < pb[st])
                    {
                        p[st] = tm + t[li][j];
                    }
                    //p[st] = min(tm + t[li][j],pb[st]);
                    pb[st] = p[st];
                }
            }
        }
        for(int i = 1;i <= h[x];i++)
        {
            int li = hh[x][i];
            for(int j = 1;j <= k[hh[x][i]];j++)
            {
                int st = a[hh[x][i]][j];
                pb[st] = p[st];
                build(st);
            }
        }
        ans += p[y];
        cout << ans << endl;
    }
    //for(int i = 1;i <= m;i++) cout <<h[i] << endl;
    return 0;
}