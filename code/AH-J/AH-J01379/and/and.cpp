#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
bool cmp(int a,int b){
    return a>b;
}
void dfs(long long yet,long long cnt,long long id){
    if(cnt==m){
        ans=max(ans,yet);
    }
    if(id>n){
        return ;
    }
    if(yet<=ans){
        return ;
    }
    for(int i=id;i<=n;i++){
        dfs(yet&a[i],cnt+1,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        dfs(a[i],1,i+1);
    }
    cout<<ans;
    return 0;
}
