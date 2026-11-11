#include <bits/stdc++.h>
#define ly cin
#define lzy cout
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int x[maxn][32];
int cnt[32];
bool vis[maxn];
int n,m;
bool check(int i,int h){
    for(int j=h+1;j<=31;j++)if(vis[j]&&!x[i][j])return false;
    return true;
}
int dfs(int h){
    if(h<0)return 0;
    int cnt1=0; 
    for(int i=1;i<=n;i++){
        if(x[i][h]&&check(i,h))cnt1++;
    }
    if(cnt1>=m){
        vis[h]=true;
        return (1<<h)+dfs(h-1);
    }
    return dfs(h-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ly>>n>>m;
    for(int i=1;i<=n;i++){
        ly>>a[i];
        int tot=0;
        int y=a[i];
        while(y!=0){
            x[i][tot]=y%2;
            y/=2;
            if(x[i][tot])cnt[tot]++;
            tot++;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=31;j>=0;j--){
    //         cerr<<x[i][j];
    //     }
    //     cerr<<"\n";
    // }
    for(int i=31;i>=0;i--){
        if(cnt[i]>=m){
            lzy<<dfs(i)<<"\n";
            return 0;
        }
    }
    lzy<<"0\n";
    return 0;
}