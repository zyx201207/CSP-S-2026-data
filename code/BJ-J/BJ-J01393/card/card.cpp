

#include <iostream>

using namespace std;

bool cnt[500009], cnt1[500009];
int posah[500009];
int posba[500009];
int survive[500009];
int card[500009];
int n, m;
int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &card[i]);
        if (!cnt[card[i]]) {
            posah[card[i]] = i;
            cnt[card[i]] = true;
        }
       // cout << card[i] << " ";
    }
   // cout << endl;
    for (int i = n; i >= 1; i--) {
        //cout << card[i] << " ";
        if (!cnt1[card[i]]) {
            posba[card[i]] = i;
            cnt1[card[i]] = true;
        }
    }

    //for (int i = 1; i <= m; i++) {
    //    cout << posah[i] << " " << posba[i] << endl;
    //}

    for (int i = 1; i <= n; i++) {
        int pos = i;
        while (pos <= n) {
            survive[card[pos]]++;
            pos = posba[card[pos]] + 1;
        }
        
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", survive[i]);
    }
    cout << endl;
    return 0;
}