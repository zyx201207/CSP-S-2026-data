#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[100005],f[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][1]=a[i];
        for(int k=1;k<=min(i,m);k++){
            for(int j=1;j<i;j++){
                f[i][k]=max(f[i][k],f[j][k-1]&a[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i][m]);
    }
    cout<<ans;
    return 0;
}
