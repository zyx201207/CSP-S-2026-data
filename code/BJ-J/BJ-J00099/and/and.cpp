#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int maxx = 0;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(m == 1){
        cout << maxx;
    }
    else if(m == n){
        int k = a[1];
        for(int i = 2;i <= n;i++){
            k = k and a[i];
        }
        cout << k;
    }
    return 0;
}