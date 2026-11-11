#include<bits/stdc++.h>
using namespace std;
int x[2000003],f[2000003]={},vis[2000003]={};
int n,d,ans=0;
void dfs(int q,int z){
    vis[q]=1;
    if(q==z) return;
    for(int i=1;i<=n;i++){
        int nx=f[i]+q;
        if(nx<n&&nx>0&&f[i]<=d&&!vis[i]){
            vis[nx]=1;
            dfs(q+nx,z);
        }

    }
    dfs(q,z+1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<n;i++){
            f[i]=x[i+1]-x[i];
            if(f[i]<=d) ans++;
        }
        //dfs(1,2);
        cout<<ans/d<<endl;
    }
return 0;
}
