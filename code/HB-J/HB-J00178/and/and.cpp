#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
int vis[200010];
int ans;
void dfs(int x,int val){
    if(x>m){
        ans=max(ans,val);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(x==1){
            vis[i]=1;
            dfs(x+1,a[i]&a[i]);
            vis[i]=0;
        }
        if(vis[i]==0){
            vis[i]=1;
            dfs(x+1,val&a[i]);
            vis[i]=0;
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
    if(m==n){
        int sum=a[1];
        for(int i=1;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
