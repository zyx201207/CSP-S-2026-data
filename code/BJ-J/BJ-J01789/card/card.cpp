#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,vis[N],a[N],x,w[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(w[a[i]]==0) w[a[i]]=i;
        else if(vis[i]==0){
            for(int j=w[a[i]];j<i;j++){
                vis[j]=w[a[i]]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) ans[a[i]]+=i;
        else ans[a[i]]=i-vis[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


