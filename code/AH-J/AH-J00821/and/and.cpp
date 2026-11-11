#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=100;
LL a[N],n,m,ans=0;
void dfs(LL cur,LL pre,LL sum){
    if(cur>m){
        ans=max(ans,sum);
        return ;
    }
    for(LL i=pre+1;i<=n;i++){
        if(cur==1) dfs(cur+1,i,a[i]);
        else dfs(cur+1,i,(sum&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
