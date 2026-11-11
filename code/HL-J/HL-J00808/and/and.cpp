#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
#define int long long
int a[N],save[N];
bool vis[N];
int n,m;
int maxn = INT_MIN;

void dfs(int depth,int start){
    if(depth == m+1){
        int ans = save[1];
    for(int i=2;i<depth;i++){
        ans &=save[i];
    }
    maxn = max(maxn, ans);
            return ;
        // ·µ»Ø
    }
    for(int i=start;i<=n;i++){
        if(!vis[i]){
            save[depth] = a[i];
            vis[i] = true ;
            dfs(depth + 1,i+1);
            vis[i] = false ;
        }
    }

}
int32_t main(){
    freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m == n){
            int ans= a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0 ;
    }
    if(m>3||n>2000){
    sort(a+1,a+n+1,greater<int>());
     int ans = a[1];
     if(a[2]==a[3]&&m==2){
            ans = a[2]&a[3];
        cout<<ans;
        return 0;
     }
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;

    }
    else{
    dfs(1,1);
     cout<<maxn;
     return 0;
    }

}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
