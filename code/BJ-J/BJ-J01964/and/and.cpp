#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, b[200000][30];
    string a[200000];
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        while (a[i] > '0'){
            int j = 0;
            b[i][j] = (a[i] - '0') % 2;
            j++;
            a[i] /= 2;
        }
    }
    return 0;
}
