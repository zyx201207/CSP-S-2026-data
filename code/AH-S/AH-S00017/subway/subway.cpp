#include<iostream>
#include<cstdio>
using namespace std;
bool g[5005][5005];
int C,n,m,d,q,w[500005],k[505],st,ed;
int a[500005],t[500005];
long long ans;
void dfs(int x,long long sum){
    if(sum>ans){
        return ;
    }
    if(x==ed){
        ans=min(ans,sum);
        return ;
    }
    for(int i=1;i<=m;i++){
        if(i==x) continue;
        if(g[x][i]){
            dfs(i,sum+g[x][i]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
            for(int l=1;l<=j;l++){
                g[l][a[l]]=t[j];
            }
        }
    }
    while(q--){
        cin>>st>>ed;
        ans=0x3f3f3f3f;
        dfs(st,0);
        cout<<ans+w[st]+w[ed]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
