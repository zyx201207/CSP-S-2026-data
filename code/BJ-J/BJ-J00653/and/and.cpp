#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=0;
void dfs(int step, int idx, int num){
    if(step == m){
        if(max1 < num) max1 = num;
        return;
    }
    for(int i = idx + 1; i <= n - m + step + 1; i ++){
        dfs(step + 1, i, num & a[i]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n-m+1; i ++){
        dfs(1,i,a[i]);
    }
    cout << max1;
    return 0;
}
