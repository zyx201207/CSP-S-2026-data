#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int x,y;
int w[5005],t[5005][5005],a[5005][5005],kk[505];
int cnt;
long long ans = 1e8,ansss = 0;
long long bfs(int xx,int yy,int ii,long long an,int cntt)
{
    if (yy == xx)
    {
        return an;
    }
    if (an != (w[x] +w[y]))
    {
        an += t[ii][xx];
    }
    if (cnt >= 20) return ans;

    for (int i = 1;i <= k;i ++)//第i条线路
    {
        for (int j = 1;j <= k;j ++)//第i条线路第j站
        {
            if (a[i][j] == xx)
            {
                for (int l = 1;l <= k;l ++)
                {
                    an += t[l][j];
                    long long ansss = bfs(a[l][j],yy,i,an,cntt +1);
                    if(ansss< ans){
                        ans = ansss;
                    }
                    an -= t[l][j];
                }
            }
        }
    }
    return ans;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i ++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i ++)
    {
        cin >> k;
        kk[i] = k;
        int j = 1,l = 1;
        for (int q = 1;q <= k;q ++)
        {
            cin >> a[i][q] >> t[i][q];
        }
    }
    for(int ww = 1;ww <= q;ww ++){
        cin >>x >> y;
        k = kk[ww];
        long long s = (w[x] + w[y]);
        if (x == y){
            cout << 0;
            return 0;
        }
        cout << bfs(x,y,1,s,0) << endl;
        ans = 0;
        anss = 0;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
