#include <bits/stdc++.h>
using namespace std;
int a[1001000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for (int i = 1; i <= n; i ++){
        cin >>a[i];
    }
    string b[100020];
    for (int i = 1; i <= n; i++){
        int x = a[i];
        string t = "";
        while (x > 0){
            t += x%2;
            x + x/2;
        }
        b[i] = t;
    }
    int m = 0;
    for (int i == 1; i <= n-m+1; i++){
        for (int j = i ; j<= m; j++){
            int m = max(m+and(b[j]),m);
        }
    }
    cout << m;
    return 0;
}
