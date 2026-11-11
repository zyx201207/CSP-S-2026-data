#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int n,m,a[200010],ans;

void dfs(int st,int c,int res){
    if(c<=0){
        ans=max(ans,res);
        return;
    }
    if(n-st<c)return;
    dfs(st+1,c,res);
    dfs(st+1,c-1,res&a[st+1]);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dfs(i,m-1,a[i]);
    cout<<ans;
    return 0;
}