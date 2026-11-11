#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans=0;
void dfs(int now,int x/*现在已经and得来的值*/,int cnt){
    if(cnt==m){
        ans=max(ans,x);
    }
    for(int i=now+1;i<=n+1;i++){
        dfs(i,x&a[now],cnt+1);
        dfs(i,x,cnt);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0x7fffffff,0);
    cout<<ans;
    return 0;
}