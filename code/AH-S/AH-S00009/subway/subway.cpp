#include<iostream>
using namespace std;
const int N=505,M=50005;
int c,n,m,d,q,st,ed,ans=1e9,w[M],k[N],a[N][M],t[N][M];
int trans(int x,int y){
    for(int i=1;i<=n;i++){
        if(i!=x){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==a[x][y])return i;
            }
        }
    }
    return 0;
}
void dfs(int line,int station,int walk){
    if(station>n)return;
    if(a[line][station]==ed){
        ans=min(ans,walk+t[line][station]);
        return;
    }
    int p=trans(line,station);
    if(p){
        for(int j=1;j<=k[p];j++){
            if(a[p][j]==a[line][station]){
                dfs(p,j+1,walk+t[p][j]+t[line][station]);
            }
        }
    }
    dfs(line,station+1,walk);
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
        cin>>st>>ed;
        int ansans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==st){
                    ans=1e9;dfs(i,j,t[i][j]);
                    ansans=min(ansans,ans);
                }
            }
        }
        cout<<w[st]+w[ed]+ansans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
