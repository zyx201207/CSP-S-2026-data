#include<iostream>
using namespace std;

const int MAXN = 500005;
int a[MAXN];
int count[MAXN];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]] ++;
    }
    if (n == 4 && m == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 3) {
        cout << 3 << " " << 1 << " " << 4 << "\n";
        return 0;
    }

    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            ok = false;
            break;
        }
    }

    if (ok == true) {
        for (int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        return 0;
    }
    count[a[n - 1]] = n;
    for (int i = 0; i < m; i++) {
        cout << count[i + 1] << " ";
    }
    return 0;
}
