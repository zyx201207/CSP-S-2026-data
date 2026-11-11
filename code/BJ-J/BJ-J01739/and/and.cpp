#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=-1;
void dfs(int now,int cnt,int sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(n-now<m-cnt) return;
    for(int i=now+1;i<=n;i++) dfs(i,cnt+1,sum&a[i]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(i,1,a[i]);
    cout<<ans;
}