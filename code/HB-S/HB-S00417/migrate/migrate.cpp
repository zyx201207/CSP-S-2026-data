#include <bits/stdc++.h>
int cang[5005][5005];
int cgs[5005][5005];
int in[5005];
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> in[i];
        }
        memset(cang,0x3f,sizeof cang);
        memset(cgs,0,sizeof cgs);
        for(int i=1;i<=n;i++)
            cang[i][i]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(in[j]-in[i]<=d)
                {
                    cang[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j || i==k || j==k) continue;
                    if(cang[i][k]+cang[k][j]<cang[i][j])
                    {
                        cang[i][j]=cang[i][k]+cang[k][j];
                    }
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j || i==k || j==k) continue;
                    if(cang[i][k]+cang[k][j]==cang[i][j])
                    {
                        cgs[i][j]++;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout << i << " " << j << " " << cgs[i][j] << endl;
                if(cgs[i][j]==2) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
