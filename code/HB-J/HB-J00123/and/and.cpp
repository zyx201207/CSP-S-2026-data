#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
int n,m,a[N],ans,f[N][N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) f[i][0]=(1<<31)-1;
    f[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=i-1;k++) f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,f[i][m]);
    cout<<ans;
    return 0;
}
