#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],h[2005],f[2005][2005];
int calc(){
    int ans=1;
    for(int i=1;i<=30;i++) ans*=2;
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        h[i]=(h[i-1]&a[i]);
        if(i==1) h[i]=a[i];
    }
    f[0][0]=calc();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=min(i,m);j++){
            f[i][j]=f[i-1][j];
            for(int k=j-1;k<=i-1;k++)
                f[i][j]=max(f[i][j],f[k][j-1]&a[j]);
        }
    cout<<f[n][m];
    return 0;
}