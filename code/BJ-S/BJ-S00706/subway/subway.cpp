#include<bits/stdc++.h>
using namespace std;

long long sum;
int c, n, m, d, q;
int w[500005], k[505];
struct node
{
    int a, t;
}b[505][500005];

int cal(int f)
{
    int minn = 10e8;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k[i]; j++)
            if(b[i][j].a == f)minn = min(minn, b[i][j].t);
    return minn;
}
int f(int x, int y)
{
    for(int i=1; i<=k[x]; i++)
        for(int j=1; j<=k[y]; j++)
            if(b[x][i].a == b[y][j].a)return b[x][i].t + b[y][j].t;
}
bool seach(int x, int y)
{
    for(int i=1; i<=k[x]; i++)
        if(b[x][i].a == y)return true;
    return false;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++)cin >> w[i];
    for(int i=1; i<=n; i++)
    {
        cin >> k[i];
        for(int j=1; j<=k[i]; j++)cin >> b[i][j].a >> b[i][j].t;
    }
    while(q --)
    {
        int x, y;
        cin >> x >> y;
        sum = w[x] + w[y] + cal(x) + cal(y);
        for(int i=1; i<n; i++)
            if(seach(i, x) && seach(i + 1, y))sum += f(i, i + 1);
            else if(seach(i, y) && seach(i + 1, x))sum += f(i + 1, i);
        cout << sum << '\n';
    }
    return 0;
}
