#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
int w[M];
int k[N],a[N][M],t[N][M];
long long ans=1e18;
void dfs(int u,int v,int line,long long res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(u==a[i][j]){
                res+=t[i][j];
                if(u==v&&i==line){
                    ans=min(ans,res);
                    return;
                }
                if(u!=v&&i!=line){
                    for(int p=j+1;p<=k[i];p++){
                        dfs(p,v,i,res);
                    }
                    res-=t[i][j];
                }
            }
        }
    }
}
void solve(int l,int r){
    ans=1e18;
    dfs(l,r,0,0);
    ans+=w[l];
    ans+=w[r];
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}
