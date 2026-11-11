#include<bits/stdc++.h>
using namespace std;

int main() {

   freopen("card.in" ,"r", stdin);
   freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int a[n];
    int card[n];
    int t[m + 1];
    memset(t, 0, sizeof(t));
    memset(card, -1, sizeof(card));
    int pos = 0;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(card[0] = -1) {
            card[0] = a[0];
            ++pos;
        } else {
            for(int i = 0; i < pos; ++i) {
                if(card[i] == a[i]) {
                    for(int j = i; j < pos; ++i) {
                        card[j] = -1;
                    }
                }
            }
            card[pos] = a[i];
            ++pos;
        }
        for(int i = 0; i < pos; ++i) {
            ++t[card[i]];
        }
    }

    for(int i = 1; i <= m; ++i){
        cout << t[i] << " ";
    }
    cout << '\n';

    return 0;
}
