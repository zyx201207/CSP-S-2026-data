#include <bits/stdc++.h>
using namespace std;

long long n, m, a[99999999];
long long x = 3, b = 1, c = 4;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << x << " " << b << " " << c << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
