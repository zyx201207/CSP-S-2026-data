#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in", "r",stdin);
    freopen("and.out", "w",stdout);
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
            }
        }
    }
    cout << a[n - m];

    return 0;
}


