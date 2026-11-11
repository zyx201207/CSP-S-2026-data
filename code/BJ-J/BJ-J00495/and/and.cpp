#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2*1e5+5;
int n,m;
int a[MAXN]={0};
int ans1=0,ans=0;
void dfs(int x,int d){
    if(x==m){
        ans=max(ans,ans1);
        return;
    }
    ++x;
    for(int i=d+1;i<=n;++i){
        int s=ans1;
        ans1=ans1&a[i];
        dfs(x,i);
        ans1=s;
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        ans1=a[i];
        dfs(1,i);
        ans1=0;
    }
    cout<<ans<<'\n';
    return 0;
}
