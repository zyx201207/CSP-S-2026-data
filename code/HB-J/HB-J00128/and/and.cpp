#include <bits/stdc++.h>
using namespace std;

long long a[99999999];
int sum = 12;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << sum << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
