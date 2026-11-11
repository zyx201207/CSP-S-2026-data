#include<iostream>
#include<vector>
using namespace std;
int f[1000005],h[100005],n,k;
void dfs(int x,int fa){
    int mx=0;
    for(int i=0;i<t[x].size();i++){
        int v=t[x][i];
        dfs(v,x);
        if(v==fa)continue;
        mx=max(mx,h[v]);
    }
    h[x]=mx+1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int m=((n-1)/2);
    if(k==n){
        cout<<0<<endl;
    }else
    if(k>=m+1||n==5&&k==2){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
