#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[5001][5001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        f[i][1]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(i>=a[j])
                f[i][j]=max(f[i][j-1],f[i-a[j]][j]+1);
            else
                f[i][j]=f[i][j-1];
        }
    }
    cout<<f[m][n];
    return 0;
}
