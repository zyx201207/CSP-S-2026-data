#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505];
int f[505];
int mdp=501;
int y;
void dfs(int de,int x){
    if(x==y){
        mdp=min(mdp,de);
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==y){
            mdp=min(mdp,de);
            return;
        }
        if(f[i])dfs(de+1,f[i]);
    }
    return;
}
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway1.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j/2]>>t[i][j/2];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int p=j+1;p<=k[i];p++){
                f[a[i][j]]=a[i][p];
                f[a[i][p]]=a[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        cin>>x>>y;
        mdp=501;
        dfs(1,x);
        cout<<(mdp-1)*t[1][1]+w[x]+w[y]<<endl;
    }
    return 0;
}
