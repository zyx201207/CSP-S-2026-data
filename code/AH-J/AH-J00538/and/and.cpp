#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200010];
int f(int x,int y){
    int cx=0,cy=0,numx[100],numy[100],num=0;
    while(x!=0){
        numx[++cx]=x%2;
        x/=2;
    }
    while(y!=0){
        numx[++cy]=y%2;
        y/=2;
    }
    for(int i=1;i<=min(cx,cy);i++){
        if(numx[i]==numy[i]&&numy[i]==1){
            num+=(1<<(i-1));
        }
    }
    return num;
}
void dfs(int t,int cnt,int sum){
    if(t==n+1){
        return ;
    }
    if(sum<=ans){
        return ;
    }
    if(cnt==m){
        ans=max(ans,sum);
        return ;
    }
    dfs(t+1,cnt+1,f(sum,a[t]));
    dfs(t+1,cnt,sum);
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,1<<30);
    cout<<ans;
    return 0;
}
