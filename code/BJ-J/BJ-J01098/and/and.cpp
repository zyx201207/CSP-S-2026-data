#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans;
void dfs(int i,int step,int cnt){
    if(step==m){
        ans=max(ans,cnt);
        return;
    }
    if(cnt==0&&step!=0){
        return;
    }
    if(i>n){
        return;
    }
    if(m-step>n-i+1){
        return;
    }
    if(step==0){
        dfs(i+1,step+1,a[i]);
    }
    else{
        dfs(i+1,step+1,cnt&a[i]);
    }
    dfs(i+1,step,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}