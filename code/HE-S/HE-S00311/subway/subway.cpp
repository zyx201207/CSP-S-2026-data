#include<bits/stdc++.h>
using namespace std;
vector<int>a[505],t[505];
int w[500005];
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            int aa, tt;
            cin >> aa >> tt;
            a[j].push_back(aa);
            t[j].push_back(tt);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(n==1)
        {
            cout << w[x]+w[y]+a[0][x]+a[0][y];
        }
    }

    return 0;
}

