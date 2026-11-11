#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int c, t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    int n;
    while(t--){
        cin >> n;
        int num;
        cout << num % n;
    }
    return 0;
}
