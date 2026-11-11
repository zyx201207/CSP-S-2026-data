#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long max_1v = -1,max_2v = -1,a[200005] = {};
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        if (a[i] > max_1v) max_1v = a[i];
    }
    if (m == 1){
        cout << max_1v;
        return 0;
    }
    if (m == 2){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                if (i == j) continue;
                if ((a[i] & a[j]) > max_2v) max_2v = a[i] & a[j];
            }
        }
        cout << max_2v;
        return 0;
    }
    return 0;
}