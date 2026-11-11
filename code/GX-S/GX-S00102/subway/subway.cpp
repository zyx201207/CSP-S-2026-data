#include<bits/stdc++.h>
using namespace std;
int kskbl;
int n,m,d,q,w[500005],xr,yr,ans,c[500005];
struct f{
    int n,a[500005],t[500005];
}a[505];
bool fin(int i,int x){
    for(int j=1;j<=a[i].n;j++){
        if(a[i].a[j]==x){
            return 1;
        }
    }
    return 0;
}
void dfs(int x,int y,int maxn){
    if(x==y){
        ans=min(ans,maxn);
        return;
    }
    for(int i=1;i<=n;i++){
        if(fin(i,x)){
            for(int j=1;j<=a[x].n;j++){
                if(c[a[x].a[j]]==0){
                    c[a[x].a[j]]=1;
                    dfs(a[x].a[j],y,maxn+a[x].t[i]);
                    c[a[x].a[j]]=0;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>kskbl>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        a[i].n=k;
        for(int j=1;j<=k;j++){
            int u,t;
            cin>>u>>t;
            a[i].a[j]=u;
            a[i].t[j]=t;
        }
    }
    while(q--){
        ans=1e9;
        cin>>xr>>yr;
        c[xr]=1;
        dfs(xr,yr,w[xr]);
        c[xr]=0;
        cout<<ans+w[yr]<<endl;
    }
    return 0;
}

