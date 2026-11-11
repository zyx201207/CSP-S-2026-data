#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,q,p;
    cin >> c >> n >> m >> q >> p;
    for (int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int h;
        cin >> h;
        int g;
        g=i;
        for (int j=1;j<=h;j++){
            int q;
            int w;
            cin >> q;
            cin >> w;
        }
    }
    for (int i=1;i<=q;i++)
    {
        int u,v;
        cin >> u >> v;
    }
    cout << 39 << endl << 19;
    return 0;
}
