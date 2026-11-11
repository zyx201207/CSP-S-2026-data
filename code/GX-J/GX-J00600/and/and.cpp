#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[100001];
    for(int i = 0; i < n ; i++){
        cin >>a[i];
        }
    int ans = 0;
    if(m == 2){
        for(int i = 0;i < n; i++){
            for(int j = i; j < n - 1; j++){
                ans = max(a[i] & a[j+1], ans);
            }
        }
    }else{

    }
    cout << ans ;

    return 0;
}
