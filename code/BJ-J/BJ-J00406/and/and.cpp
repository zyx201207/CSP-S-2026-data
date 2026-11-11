#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int chose[200010];
int ans=0;
void dfs(int cur,int now){
    if(now<ans&&now!=-1)return;
    if(cur>m){
        ans=max(ans,now);
        return;
    }
    for(int i=chose[cur-1]+1;i<=n-m+cur;i++){
        chose[cur]=i;
        dfs(cur+1,(now==-1?a[i]:a[i]&now));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,-1);
    cout<<ans;
    return 0;
}
