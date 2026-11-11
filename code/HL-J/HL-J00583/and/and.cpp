#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
long long n,r,ans=0;
long long a[MAX],b[MAX],c[MAX];
bool vis[MAX];
void dfs(int k){
    if(k>r){
        for(int i=1;i<k;i++){
            ans=max(ans,c[i]&c[i+1]);
        }
        return;
    }
    for(int i=1;i<=r;i++){
        if(vis[i]==false){
            vis[i]=true;
            c[k]=a[i];
            dfs(k+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
