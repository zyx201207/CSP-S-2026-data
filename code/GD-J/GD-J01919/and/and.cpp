#include <iostream>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[200005] = {};
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    if (m == 1){
        long long max = a[0];
        for (long long i = 1; i < n; i++){
            if (a[i] > max){
                max = a[i];
            }
        }
        cout << max;
    }
    else if (m == 2){
        long long max = a[0] & a[1];
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if ((a[i] & a[j]) > max){
                    max = a[i] & a[j];
                }
            }
        }
        cout << max;
    }
    return 0;
}
