#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}
