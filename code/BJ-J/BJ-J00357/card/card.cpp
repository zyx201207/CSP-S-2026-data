#include<bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    
    int n, m, a[200005];
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << n << ' ';
    }
    
    return 0;
    
}