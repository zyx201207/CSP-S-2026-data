#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000];
int n,m;
int ans;
void dfs(int k,int id,int now,int sum){
    if(id==k&&now<=n&&id<=n){
        ans=max(sum,ans);
        return;
    }
    if(now<=n&&id<=n){
        dfs(k,id,now+1,sum&a[now+1]);
        for(int i=1;i<=n;i++){
            dfs(k,id+1,now+i,sum&a[now+i]);
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(m,1,i,a[i]);
    }
    cout<<ans;
    return 0;
}
