#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],maxn;
void dfs(int d,int t,int ans){
    if(t == m){
        maxn = max(maxn,ans);
        return;
    }
    if(d == n)return;
    dfs(d+1,t,ans);
    dfs(d+1,t+1,ans&a[d+1]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,0,2147483647);
    dfs(1,1,a[1]);
    cout << maxn;
    return 0;
}
