#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

int arr[MAXN];
int cnt[MAXN];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++) {
        vector<int> tab;
        for(int j=i; j<=N; j++) {
            int p = 0;
            for(int k=0; k<tab.size(); k++) {
                if (tab[k] == arr[j]) {
                    p = k;
                    break;
                }
            }
            if (!p) {
                tab.push_back(arr[j]);
            } else {
                while (tab.size() > p) tab.pop_back();
                tab.push_back(arr[j]);
            }
        }
        for(int elem : tab) {
            cnt[elem]++;
        }
    }
    for(int i=1; i<=M; i++) cout << cnt[i] << "\n";
    return 0;
}