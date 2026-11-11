#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a[500005],spA=0,spB=0,ans=0;
void dfs(LL id,LL sum){
    if(id>n){
        map<LL,LL>vis;
        for(int i=1;i<=n;i++){
            vis[a[i]]++;
            ans=max(ans,vis[a[i]]);
        }
        return ;
    }
    for(LL i=0ll;i+sum<=m;i++){
        a[id]+=i;
        dfs(id+1ll,sum+i);
        a[id]-=i;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==i) spA++;
    }
    if(spA==n){
        LL tot=1ll,l=0ll;
        while(l+1ll<=m){
            tot++;
            l++;
            m-=l;
        }
        cout<<tot;
        return 0;
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]==a[i-1]-a[i-2]) spB++;
    }
    if(spB==n-2){
        LL tot=1ll,l=a[2]-a[1];
        while(l<=m){
            tot++;
            m-=l;
            l+=a[2]-a[1];
        }
        cout<<tot;
        return 0;
    }
    dfs(1ll,0ll);
    cout<<ans;
    return 0;
}
