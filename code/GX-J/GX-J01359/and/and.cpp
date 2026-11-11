#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int maxf = 0, p1, p2;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int x = a[i] & a[j];
            if (x > maxf){
                maxf = x;
                p1 = i;
                p2 = j;
            }
        }
    }
    a[p1] = 0;
    a[p2] = 0;
    for (int i = 2; i < m; i++){
        int maxn = 0;
        for (int j = 0; j < n; j++){
            int x = maxf & a[j];
            if (x > maxn){
                maxn = x;
                p1 = j;
            }
        }
        a[p1] = 0;
        maxf = maxn;
    }
    cout << maxf;
    return 0;
}
