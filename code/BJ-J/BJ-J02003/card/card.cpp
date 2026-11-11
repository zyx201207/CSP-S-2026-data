#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],nxt[N],nml[N],vis[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nxt[nml[a[i]]]=i;
        nml[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                ans[a[j]]++;
                vis[a[j]]=1;
            }
            if(nxt[j]!=0){
                j=nxt[j]-1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
