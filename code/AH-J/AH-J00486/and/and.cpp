#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}
#define int long long
const int N=2e5+10;
int a[N];
int n,m,ans;
void dfs(int x,int cnt,int ret){
    if(cnt>=m){
        ans=max(ans,ret);
        return;
    }
    if(x>n){
        return;
    }
    dfs(x+1,cnt,ret);
    ret=(ret&a[x]);
    dfs(x+1,cnt+1,ret);
}
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n*m>=1e8 || n>=2e5){
        sort(a+1,a+1+n,cmp);
        cout<<a[m]<<"\n";
    }else{
        dfs(1,0,-1);
        cout<<ans<<"\n";
    }
    return;
}
