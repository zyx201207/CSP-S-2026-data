#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500005],s,u,v;
int a[500005],t[500005];
vector<int> g[500005];
int mx=-0x3f3f3f3f,sum;
void dfs(int x){
    if(x==v){
        mx=max(mx,sum);
        return ;
    }
    for(int i=0;i<g[x].size();i++){
        int h=g[x][i];
        sum+=t[h];
        dfs(h);
        sum-=t[h];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=s;j++){
            scanf("%d%d",&a[i],&t[i]);
            if(i!=1){
                g[i-1].push_back(a[i]);
            }
        }
    }
    while(q--){
        cin>>u>>v;
        sum+=k[u]+k[v]+t[u];
        dfs(u);
        cout<<mx<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
