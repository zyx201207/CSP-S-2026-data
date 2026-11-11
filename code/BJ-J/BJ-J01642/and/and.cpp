#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[200010];
int a[200010];
long long ans;
int sa[200010];
void dfs(int u){
    if(u==m){
        long long res=sa[a[1]];
        for(int i=2;i<=u;i++){
            res&=sa[a[i]];
        }
        ans=max(ans,res);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            a[u+1]=i;
            dfs(u+1);
            vis[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> sa[i];
    }
    dfs(0);
    cout << ans << "\n";
}
