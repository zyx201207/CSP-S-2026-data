#include<bits/stdc++.h>
using namespace std;
int f[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int m,n;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }
    if (m == 2){
        for(int i = 1; i <= m + 1; i++){
            if (f[i] != f[i-1]){
                cout << i << " ";
            }
        }
    }
    if(m == 1){
        cout<<n;
    }
    return 0;
}
