#include<bits/stdc++.h>
using namespace std;
int n,m,a[514514],ans[314514];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        ans[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
