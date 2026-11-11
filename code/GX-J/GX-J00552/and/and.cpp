#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010];

int mxand(int p,int b){
    if (n == 0)
        return a[b];
    int maxand = 0;
    for (int i = 1 ; i < n - b ; i++)
        maxand = max(maxand,a[b] & mxand(p - 1, b + i));
    return maxand;
}

int main(){
    int maxand = 0;
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for (int i = 0 ; i < n ; i++){
        maxand = max(maxand, mxand(m, i));
    }
    cout << maxand;
    return 0;
}
