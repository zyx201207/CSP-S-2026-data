#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
vector<ll> v;
ll ans=0;
void dfs(int x,int cnt,ll num){
    if(x>=n||cnt>m) return;
    if(cnt==m){
        ans=max(ans,num);
        return;
    }
    if(num==-1) dfs(x+1,cnt+1,v[x]);
    else dfs(x+1,cnt+1,num&v[x]);
    dfs(x+1,cnt,num);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    v.resize(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<ll>());
    dfs(0,0,-1);
    cout<<ans<<'\n';
    return 0;
}