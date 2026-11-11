#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p;
ll a[200010];
ll maxn=0;
void dfs(ll cur,ll pos,ll cnt){//已经选择了cur个数,接下来判断第pos个数,此时的答案为cnt;
    if(cur==m){
        maxn=max(maxn,cnt);
        return ;
    }
    if(pos>n||cnt<maxn)   return ;
    if(p==pos)  dfs(cur,pos+1,cnt);
    else{
        
    dfs(cur+1,pos+1,cnt^a[pos]);
    dfs(cur,pos+1,cnt);
        }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)    cin>>a[i];
    ll mxn=0;
    for(ll i=1;i<=n;i++){
        mxn=max(mxn,a[i]);
        p=i;
    }
    if(m==1)    cout<<mxn;
    else if(m==n){
        ll ans=a[1];
        for(ll i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    else{
        dfs(1,1,mxn);
        cout<<maxn;
    }
    return 0;
}
