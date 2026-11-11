#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;int w[500005],a[500005][505],b[505][32];bool p[500005];//p用来标记每个站点是否走过
auto dfs(int x,int y,int t){// t is time
    if(x==y){
        ans=min(ans,t);
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[x][i]){
            for(int j=1;j<=b[i][0];j++){
                if(b[i][j]!=x&&p[b[i][j]]==0){
                    p[b[i][j]]=1;
                    dfs(b[i][j],y,t+a[b[i][j]][i]+a[x][i]);
                    p[b[i][j]]=0;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;b[i][0]=k;//我能想到把第0位用来存储经过了几站，我简直是天才
        for(int j=1;j<=k;j++){
            cin>>b[i][j];cin>>a[b[i][j]][i];
        }
    }
    for(int i=1;i<=q;i++){
        memset(p,0,sizeof(p));
        int x,y;
        cin>>x>>y;
        ans=1e9;
        p[x]=1;
        dfs(x,y,w[x]+w[y]);
        cout<<ans<<endl;
    }
    return 0;
}
