#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,q,op;
long long a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i >= 2 && a[i] != a[1]){
            op = 1;
        }
    }
    if(m == 1 || op == 0){
        for(int i = 1;i <= n;i++){
            ans = max(ans,a[i]);
        }
        cout << ans;
    }
    else{
        for(int i = 1;i <= n;i++){
            ans = min(ans,a[i]);
        }
        cout << ans;
    }

    return 0;
}
