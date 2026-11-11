#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int b[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < i; j++){
            v.push_back(0);
        }
        for(int j = i; j < n; j++){
            v.push_back(a[j]);
            for(int x = j - 1; x >= i; x--){
                if(a[j] == v[x]){
                    for(int y = x + 1; y <= j; y++){
                        v[y] = 0;
                    }
                }
            }
        }
        for(int x : v){
            b[x]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << b[i] << " ";
    }
    return 0;
}
