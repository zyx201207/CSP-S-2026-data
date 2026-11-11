#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int n, m, a[500010], b[300010], c[300010];

int main() {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) {
        for(int i=0; i<v.size(); i++) v.pop_back();
        for(int j=i; j<n; j++) {
            if(b[a[j]]) for(int i=0; i<b[a[j]]-i; i++) v.pop_back();
            b[a[j]] = i;
            v.push_back(a[j]) ;
        }
        for(int i : v) c[i]++;
    }
    for(int i=0; i<n; i++) cout << c[i];

    return 0;
}
