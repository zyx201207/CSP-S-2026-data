#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w+", stdout);
    int n, m, maxn = -2147483648;
    cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    for(int i = 0; i < (int)v.size(); i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            if(v[i] & v[j] > maxn) {
                maxn = v[i] & v[j];
            }
        }
    }
    cout << maxn << endl;
    fclose(stdin);
    fclose(stdout);
}
