#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int a[500005][505],t[500005][505];
int r[505][3],k[505],ans=1e9;
bool v[5005][5005];
void dfs(int sx,int sy,int kk){
    if(sy==r[kk][2]){
        return ;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            if(v[i][j]==true){
                ans+=t[i][j]+w[i];
                dfs(i,j,kk);
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
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[a[i][j]][j];
            v[a[i][j]][a[i][j-1]]=true;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i][1]>>r[i][2];
    }
    if(c>=7 && c<=11){
        for(int l=1;l<=q;l++){
            for(int i=1;i<=n;i++){
                for(int j=i;j<=k[i];j++){
                    if(v[i][j] && i==r[l][1]){
                        dfs(i,j,l);
                    }
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(c>=12 && c<=19){
        return 0;
    }
    if(c==22 || c==23){

        return 0;
    }
    return 0;
}
