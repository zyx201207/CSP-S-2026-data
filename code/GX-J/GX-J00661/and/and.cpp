#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 2e5+5;
int n, m, ans;
vector<int> a, newa;

int main(){
    ios::sync_with_stdio(false);
    file(and);

    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int k = 29; ~k; --k){
        newa.clear();
        for(int i = 0; i < n; ++i)
            if(a[i] >> k & 1) newa.push_back(a[i]);
        if(newa.size() >= m){
            ans |= 1 << k;
            n = (a = newa).size();
        }
    }

    cout << ans;

    return 0;
}
