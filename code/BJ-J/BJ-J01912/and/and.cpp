#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int s = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    s = a[n];
    for (int i = n-1; i >= n-m+1; --i){
        s = s&a[i];
    }
    cout << s;
    return 0;
}
