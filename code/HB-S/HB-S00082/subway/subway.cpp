#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;

    int w[m+1];
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }

    int k[n+1];
    int a[n+1][10^6];
    int t[n+1][10^6];
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=2*k[i];i++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }

    int x[q+1];
    int y[q+1];
    for(int i=1;i<=q;i++)
    {
        cin >> x[i] >> y[i];
    }
//input is end;

    int i0,j0,i1,j1;
    for(int l=1;l<=q;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*k[i];j++)
            {
                if(a[i][j]==x[l])
                {
                    i0=i;
                    j0=j;
                    break;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*k[i];j++)
            {
                if(a[i][j]==y[l])
                {
                    i1=i;
                    j1=j;
                    break;
                }
            }
        }
        cout << w[x[l]]+t[i0][x[l]]+t[i0][y[l]]+w[y[l]] << endl;
    }



    return 0;
}
