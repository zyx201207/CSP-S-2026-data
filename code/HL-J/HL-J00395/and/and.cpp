#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m;
int vis[500010];
int ans=INT_MIN;
int nm;
void dfs(int k,int sum){
    if(k==0){
        ans=(sum>ans?sum:ans);
        nm=sum;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(k-1, sum & a[i] );
            vis[i]=0;
        }
    }
    //cout<<k<<" "<<sum<<endl;

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(m-1,a[i]);
        //cout<<nm<<endl;
        vis[i]=0;
    }
    cout<<ans;
    //cout<<(nm>ans)<<endl;
}
