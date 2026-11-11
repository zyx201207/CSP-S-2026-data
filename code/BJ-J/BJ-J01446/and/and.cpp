#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n,m;
int a[N];
int mx;
void dfs(int rest,int num,int last){
    if(rest == 0){
        mx = max(mx,num);
        return;
    }
    for(int i = last + 1;i <= n - rest + 1;i++){
        dfs(rest - 1,num & a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n - m + 1;i++){
        dfs(m - 1,a[i],i);
    }
    cout << mx;
    return 0;
}
