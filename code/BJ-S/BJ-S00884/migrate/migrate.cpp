#include<bits/stdc++.h>
using namespace std;
int ccc,T,n,d;
const int N=3e5+10;
int a[N],c[N];
bool vis[N];
vector<int> g[N];
void dfs(int x,int y,int fa,int ans){
   // cout<<x<<" ";
    if(x==y){
        c[ans]++;
        cout<<endl;
        return ;
    }
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        vis[u]=1;
        dfs(u,y,x,ans+a[u]-a[x]);
        vis[u]=0;

    }

    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>ccc>>T;
    while(T--){
            int x;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
    x=a[i]-a[i-1];
        }
        if(x==d){
            cout<<0<<endl;
            continue ;
        }
        if(n<4){
            cout<<0<<endl;
            continue ;
        }
        cout<<(n-1)-max(4,d/x+1)+2<<endl;

    }
       // dfs(1,4,0);
      //  for(int i=1;i<=n;i++)cout<<c[i]<<" ";

    return 0;
}
