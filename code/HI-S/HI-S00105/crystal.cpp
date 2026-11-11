#include <bits/stdc++.h>
using namespace std;
#define int64 long long

int64 n, m, maxvalue = 1;
vector<int64> crystals(500005);

int64 maxsame(vector<int64> arr) {
    int64 maxvalue = 1;
    unordered_map<int64, int64> counts;
    for (int i = 1;i <= n; i++){
        counts[arr[i]]++;
        maxvalue = max(maxvalue, counts[arr[i]]);
    }
    return maxvalue;
}

void best(int cur) {
    while (m--) {
        int64 max1 = 1, max2 = 1;
        crystals[cur]++;
        max1 = maxsame(crystals);
        crystals[cur]--;
        crystals[cur+1]++;
        max2 = maxsame(crystals);
        crystals[cur+1]--;
        cout << "m=" << m << " max1=" << max1 << " max2=" << max2 << "\n";
        if (max1 >= max2) {
            crystals[cur]++;
            maxvalue = max1;
        }
        else {
            crystals[cur+1]++;
            maxvalue = max2;
            cur++;
        }
    }
    return ;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> crystals[i];
    }
    best(1);
    cout << maxvalue;
    
    return 0;
}
