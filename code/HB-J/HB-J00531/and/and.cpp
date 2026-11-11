#include <bits/stdc++.h>
using namespace std;
int n,m,maxx[20005];
int a[200005],f[20005][20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(maxx,-0x3f3f3f3f,sizeof(maxx));
    memset(f,-0x3f3f3f3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j]);
            f[i][j]=max(maxx[j-1]&a[i],f[i][j]);
            maxx[j]=max(maxx[j],f[i][j]);
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i][m]);
    }
    cout<<ans;
    return 0;
}
