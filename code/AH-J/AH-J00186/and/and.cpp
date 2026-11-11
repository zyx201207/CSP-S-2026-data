#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,max1,max2,x;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int f[n+5][m+5];
    for(i=1;i<=n;i++)cin>>a[i];
    f[1][1]=a[1];
    max1=-1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>max1)
        {
            max1=a[i];
        }
        f[i][1]=max1;
    }
    for(i=2;i<=n;i++)
    {
        if(m<=i)
        for(j=2;j<=m;j++)
        {
            max1=-1;
            max2=-1;
            for(k=1;k<=i-1;k++)
            {
                if(f[k][j]>max1)max1=f[k][j];
                if(f[k][j-1]>max2)max2=f[k][j-1];
            }
            x=max2&a[i];
            f[i][j]=max(max1,x);
        }
    }
    cout<<f[n][m];
    fclose(stdout);
    return 0;
}
