#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],f[2010][2010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        f[i][1]=a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=min(i,m);j++){
            f[i][j]=max(f[i-1][min(i-1,j)],f[i-1][j-1]&a[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}
