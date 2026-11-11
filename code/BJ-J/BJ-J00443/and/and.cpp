#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans=0,flag[200005];
void dfs(int d,int now){
    if(now<=ans)return;
    if(d==m){
        ans=now;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){flag[i]=1;
        dfs(d+1,now&a[i]);
        flag[i]=0;}
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){flag[i]=1;dfs(1,a[i]);flag[i]=0;}
    cout<<ans;
    return 0;
}
