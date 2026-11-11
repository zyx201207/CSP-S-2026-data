#include <bits/stdc++.h>
using namespace std;

bool cmp(int o, int p){
    return o>p;
}

long long n, m, ans;
long long a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out" ,"w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    ans=a[1];
    for(int i=2; i<=m; i++){
        ans=(ans & a[i]);
    }
    cout << ans;
    return 0;
}
