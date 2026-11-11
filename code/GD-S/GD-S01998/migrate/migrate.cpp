#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int e,mn=1e9,num=0;
    auto dfs=[&](auto&& self,int id,int cnt)->void{
        if(id==e){
            if(cnt==mn){
                num++;
            }
            else if(cnt<mn){
                mn=cnt;
                num=0;
            }
            return;
        }
        for(int i=id+1;i<=e;i++){
            if(a[i]-a[id]<=d){
                self(self,i,cnt+1);
            }
        }
    };
    int ans=0;
    for(int i=1;i<=n;i++){
        e=i;
        for(int j=1;j<=e;j++){
            num=0;
            mn=1e9;
            dfs(dfs,j,0);
            if(num==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}