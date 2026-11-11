#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],t[500005],adj[500005],cnt[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        cnt[i]=1;
        if(!t[a[i]]){
            adj[i]=i+1;
        }else adj[i]=t[a[i]];
        t[a[i]]=i;
    }

    for(int i=1;i<=n;i++){
            //cout<<adj[i]<<" ";
        cnt[adj[i]]+=cnt[i];
        ans[a[i]]=cnt[i];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
