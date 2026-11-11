#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[501][50005],t[501][50005],k[501];
bool cz[50005][505],b[501][50005];
int c,n,m,d,q;
int ans=-1;
void dfs(int q,int z,int t1,int line){
    if(ans!=-1&&t1+w[z]>=ans){
        return;
    }
    if(cz[z][line]==1){
        ans=t1+t[line][z]+w[z];
        return;
    }
    for(int i=1;i<=n;i++){
        if(cz[q][i]==1&&i!=line&&b[i][q]==0){
            b[i][q]=1;
            dfs(q,z,t1+t[line][q]+t[i][q],i);
            b[i][q]=0;
        }
    }
    for(int i=1;i<=k[line];i++){
        if(a[line][i]!=q&&b[line][i]==0){
            b[line][i]=1;
            dfs(a[line][i],z,t1,line);
            b[line][i]=0;
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
            cin>>a[i][j]>>t[i][a[i][j]];
            cz[a[i][j]][i]=1;
        }
    }
    while(q--){
        int x1,y1;
        cin>>x1>>y1;
        for(int i=1;i<=n;i++){
            if(cz[x1][i]==1){
                b[i][x1]=1;
                dfs(x1,y1,w[x1]+t[i][x1],i);
                b[i][x1]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
