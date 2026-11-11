#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=1e5+5;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int x,y,f=0,ans=INT_MAX;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x) f=t[i][j];
                if(a[i][j]==y&&f>0) ans=min(t[i][j]+f,ans);
            }
        }
        if(f>0) cout<<ans+w[x]+w[y]<<endl;
    }
}
