
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[505][505],as[505][505],zd[505][505],c,d,q,zt[1005],pl[1005],ans=2e9,lo;
//greater
bool vis[1005];
void dfs(ll shi,ll wei,ll zhong){
    if(shi>ans){
        return;
    }
    if(wei==zhong){
        ans=min(ans,shi);
        return;
    }
    for(int i=1;i<=m;i++){
        if(!vis[i] && zd[wei][i]!=0){
            vis[i]=1;
            dfs(shi+zd[wei][i],i,zhong);
            vis[i]=0;
        }
    }
    return;
}
void dfs2(ll shi,ll wei,ll zhong){
    if(shi>ans){
        return;
    }
    if(wei==zhong){
        ans=min(ans,shi);
        return;
    }
    for(int i=1;i<=m;i++){
        if(!vis[i] && zd[wei][i]!=0){
            vis[i]=1;
            dfs2(shi+1,i,zhong);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;//n线路数，m站台数 d单站台最大线路 q提问
    for(int i=1;i<=m;i++){
        cin>>zt[i];
    }
    for(int i=1;i<=n;i++){
        cin>>pl[i];
        for(int j=1;j<=pl[i];j++){
            cin>>a[i][j]>>as[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=pl[i];j++){
            for(int k=1;k<=pl[i];k++){
                if(j!=k){
                    zd[a[i][j]][a[i][k]]=as[i][j]+as[i][k];
                    zd[a[i][k]][a[i][j]]=as[i][j]+as[i][k];
                    lo=zd[a[i][k]][a[i][j]]=as[i][j]+as[i][k];
                }
            }
        }
    }
    if((1<=c && c<=6)|| c==20 || c==21){
        for(int i=1;i<=q;i++){
            ll qi,zho;
            cin>>qi>>zho;
            vis[qi]=1;
            dfs(0,qi,zho);
            vis[qi]=0;
            cout<<ans+zt[qi]+zt[zho]<<'\n';
            ans=2e9;
        }
    }else if(7<=c && c<=11){
    }else if(12<=c && c<=19){
        for(int i=1;i<=q;i++){
            ll qi,zho;
            cin>>qi>>zho;
            vis[qi]=1;
            dfs2(0,qi,zho);
            vis[qi]=0;
            cout<<ans*(lo)+zt[qi]+zt[zho]<<'\n';
            ans=2e9;
        }
    }else if(c==20 || c==21){

    }else{
        cout<<"可惜了";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

