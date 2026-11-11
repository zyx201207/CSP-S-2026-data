#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[200005],m,n;
bool vis[200005],flag;
bool comp(ll a,ll b){
    return a>b;
}
ll dfs(ll x,ll l,ll nw){
    if(l==0)
        return nw;
    ll ans=0;
    for(int i=x;i<=n-l+1;i++)
        ans=max(dfs(i+1,l-1,(nw&num[i])),ans);
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    if(n<=10000){
        cout<<dfs(0,m,2147483647)<<endl;
        return 0;
    }
    sort(num+1,num+n+1,comp);
    cout<<num[m]<<endl;
    return 0;
}
