#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans = -1e9;
void dfs(&vector<int> a,int w,int y,int e){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    if(y == m){
        ans = max(ans,e);
    }
    if(w > n){
        return;
    }
    dfs(a,w + 1,y,e);
    dfs(a,w + 1,y + 1,(e & a[w]));
}
int main(){
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    dfs(a,1,0,1073741825);
    cout << ans << endl;
    return 0;
}
