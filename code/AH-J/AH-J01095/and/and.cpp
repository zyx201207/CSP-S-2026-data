#include<bits/stdc++.h>
using namespace std;
#define ffor(i,a,b) for(ll (i)=(a);(i)<(b);++(i))
typedef long long ll;
ll n,m,ans;
ll a[200100];
void dfs(ll i,ll ch,ll am){
    if(ch>m) return;
    if(n-i<m-ch) return;
    if(i>=n){
        if(ch==m)ans=max(ans,am);
        return;
    }
    dfs(i+1,ch,am);
    dfs(i+1,ch+1,(am==0)?(a[i]):(am&a[i]));
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll maxn=-1;
    ffor(i,0,n){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn<<'\n';
        return 0;
    }
    if(m==2){
        sort(a,a+n);
        ll i=0;
        while(a[i]!=a[i+1]&&i<n-1)i++;
        cout<<a[i];
    }
    dfs(0,0,0);
    cout<<ans<<'\n';
    return 0;
}