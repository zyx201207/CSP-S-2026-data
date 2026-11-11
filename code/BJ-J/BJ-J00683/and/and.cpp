#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],num,vis[200010],ans[200010];
long long last;
void dfs(int step){
    if(step > m){
        long long mx = a[ans[1]];
        for(int i = 2;i <= m;i++) mx &= a[ans[i]];
        last = max(mx,last);
        return;
    }
    for(int i = ans[step-1]+1;i <= n;i++){
        if(vis[i] == 0){
            vis[i] = 1;
            ans[step] = i;
            dfs(step+1);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        num = max(num,a[i]);
    }
    if(m == 1) cout << num;
    else{
        dfs(1);
        cout << last;
    }
    return 0;
}
