#include <bits/stdc++.h>
using namespace std;

/*
  csp rp++

  ccf I !love you

  I won't give up, no I won't give in
  Till I reach the end and I'll start again
*/

int card[300005];
int a[500005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        if(i > 1 && a[i] != a[i-1]){
            cout << i - 1 << " ";
        }
    }
    cout << n << "\n";
    return 0;
}
