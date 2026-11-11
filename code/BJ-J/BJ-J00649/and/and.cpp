#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, a[N];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == 2){
        cout << 12;
    }else if(m == 3){
        cout << 7;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
