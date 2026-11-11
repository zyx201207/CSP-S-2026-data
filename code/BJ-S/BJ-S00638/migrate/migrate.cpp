#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,d;
const int N=1e3+10;
int a[N];
int dis[N][N];
map<int,int>mp;
void dfs(int x,int dis,int l,int r){
    if(x==r){
        mp[dis]++;
        return ;
    }
    for(int i=x;i<=r;i++){
        if(abs(a[i]-a[x])<=d) dfs(i,dis+1,l,r);
    }
}
void solve(){
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dfs(j,0,j,i);
            for(auto &p:mp){
                int f=p.first,s=p.second;
                if(s==2) ans++;
            }
            mp.clear();

        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin >>c;
    cin >> t;
    while(t--) solve();
    return 0;
}
