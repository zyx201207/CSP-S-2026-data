#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a[200005],ans=1,tot=1,vis[200005];
bool cmp(LL a,LL b){return a>b;}
void dfs(LL id,LL sum,LL up){
    if(id>m){
        ans=max(ans,sum);
        return ;
    }
    for(LL i=up+1;i<=n;i++){
        dfs(id,sum,i);
        dfs(id+1,sum&a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    LL l=a[1];
    while(l!=0){
        tot*=2;
        l/=2;
    }
    tot--;
    dfs(1ll,tot,0ll);
    cout<<ans;
    return 0;
}
