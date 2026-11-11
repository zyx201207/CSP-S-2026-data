#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> cnt;
    for (int i = 0; i <= m; i++){
        cnt.push_back(0);
    }
    for (int i = 0; i < n; i++){
        vector<bool> cards;
        vector<int> b;
        for (int j = 0; j <= m; j++){
            cards.push_back(0);
        }
        for (int j = i; j < n; j++){
            b.push_back(a[j]);
            if (!cards[a[j]]){
                cards[a[j]] = 1;
            }
            else{
                int len = b.size();
                for (int k = len - 2; b[k] != a[j]; k--){
                    cards[b[k]] = 0;
                    b.erase(b.begin() + k);
                }
                b.erase(b.begin()+b.size()-1);
            }
        }
        int len = b.size();
        for (int j = 0; j < len; j++){
            cnt[b[j]]++;
        }
    }
    for (int i = 1; i <= m; i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
