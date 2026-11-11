#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(b[a[i]] == 0) b[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        cout << n + 1 - b[i] << ' ';
    }
    return 0;
}
//Trick||Treat!
