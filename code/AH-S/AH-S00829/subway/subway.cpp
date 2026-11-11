#include<bits/stdc++.h>
using namespace std;
int w[500005],t[500005],a[500005][505],gs[500005],n,m,d,q;
int f(int i,int x,int y){
    int ans=50000000;
    if(x==y) return w[y]+a[i][y];
    for(int j=x+1;j<=m;j++){
        if(a[i][j]==0) continue;
        if(j==y) return w[y]+a[i][y];
        int minn=50000000;
        for(int k=1;k<=n;k++){
            if(k==i) continue;
            if(a[k][j]){
                    int qwe=f(k,j,y)+a[k][j]+a[i][j];
                minn=min(minn,qwe);
            }
        }
        ans=min(ans,minn);

    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        int k,x,y;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            a[i][x]=y;
        }
    }
    while(q--){
        int x,y,ans=5000000;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            if(a[i][x]) {
                int qwe=f(i,x,y)+w[i]+a[i][x];
                ans=min(ans,qwe);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
