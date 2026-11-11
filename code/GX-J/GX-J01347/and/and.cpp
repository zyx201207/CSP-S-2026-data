#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define per(i,a,b) for (int i=a;i>=b;i--)
#define ll long long
using namespace std;
const int N=2*1e5+5;
ll n,m,a[N],s[N],ans;
bool cmp(ll x,ll y){return x>y;}

void dfs(int idx,int x,ll res){
    if(x==m) {
        ans=max(ans,res);
        return;
    }
    for(int i=idx;i<=n;i++){
        dfs(i+1,x+1,res&a[i]);
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=2000) {
        for(int i=1;i<=n;i++){
            dfs(i+1,1,a[i]);
        }
        cout<<ans;
    }
    //A:
    else {
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++)ans=ans&a[i];
        cout<<ans;
    }
    return 0;
}
