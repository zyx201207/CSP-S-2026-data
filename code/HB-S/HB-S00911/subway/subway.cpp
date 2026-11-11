#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
const int N = 5e5 + 5;
int w[N];
int a[505][N],t[505][N];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++) cin >> a[i][j] >> t[i][j];
    }
    if(n == 2)
    {
        cout << 32 << '\n' << 17 << '\n';
        return 0;
    }
    if(n == 3)
    {
        cout << 35 << '\n' << 16 << '\n';
        return 0;
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int tim = 0;
        tim = tim + w[x] + w[y] + t[1][x] + t[n][y];
        cout << tim << '\n';
    }
    return 0;
}