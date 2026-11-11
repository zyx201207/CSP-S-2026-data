#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
    long long  n = 0, m = 0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 1; i <= m; i++){
        n = a[i-1] & a[i];
    }
    cout << n;
    return 0;
}
