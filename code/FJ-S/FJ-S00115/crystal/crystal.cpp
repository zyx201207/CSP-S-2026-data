#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
using numtype = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    numtype n, m;
    cin >> n >> m;

    vector<numtype> arr(n, 0);
    for (numtype i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());
    numtype v = arr[0];

    deque<numtype> able;
    able.emplace_back(arr[0]);
    numtype ans = 1;

    __int128 cost = 0;

    for (numtype i = 1; i < n; ++i){
        cost += able.size() * (arr[i] - arr[i - 1]);
        while (cost > m){
            cost -= arr[i] - able.front();
            able.pop_front();
            //cerr << "#" << able.size() << "\n";
        }

        //cerr << able.size() << "\n";

        able.push_back(arr[i]);

        if (able.size() > ans) ans = able.size();
    }

    cout << ans;

    return 0;
}
