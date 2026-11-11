#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int a[maxn];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    int ansa = 0, ansb = 0;
    for (int play = 1; play <= n; play ++){
        bool pda = 0, pdb = 0;
        for (int i = play; i <= n; i ++){
            int x = a[i];
            if (x != a[i - 1]){
                if (x == 1 && pda == 1) pdb = 0;
                else if (x == 2 && pdb == 1) pda = 0;
            }

            if (x == 1) pda = 1;
            else pdb = 1;
        }

        if (pda) ansa ++;
        if (pdb) ansb ++;
    }
    cout << ansa << " " << ansb;
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    solve();

}
