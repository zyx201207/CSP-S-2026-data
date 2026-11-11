#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("and.in","r",stdin);
 //   freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int sr[n+1],f[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        cin>>sr[i];
    }

    for(int i=1;i<=m;i++)
    {
        f[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        f[i][0]=0;
        for(int j=1;j<=m;j++)
        {
            if(j+1>=m)
            {
                f[i][j]=f[i][j-1];

            }
            else
            {
                f[i][j]=max(f[i-1][j]&sr[i],f[i][j-1]);

            }

        }
    }
    cout<<f[n][m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
