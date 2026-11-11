#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[505][500005],t[505][500005,cnt[500005];
int main(){
    freeopen("subway.in","r",stdin);
    freeopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>k[i];
        for(int j = 1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            cnt[a[i][j]]+=t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = w[x]+w[y]+cnt[x]+cnt[y];
        cout<<ans<<endl;
    }
    return 0;
}
