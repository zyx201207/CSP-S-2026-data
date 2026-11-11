#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
const int N=1e3+10;
int n,k,a[N][N],c,t,s,H;
void dfs(int u,int fa,int h){
    for(int i=1;i<=n;i++){
        if(i!=fa&&a[u][i]){
            dfs(i,u,h+1);
        }
    }
    H=max(h,H);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            s=u;
            a[u][v]=a[v][u]=1;
        }
        dfs(s,0,0);
        cout<<H/k<<"/n";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}