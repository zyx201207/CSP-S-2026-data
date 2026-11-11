#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10000+10],  d[10000+10];
int all = 1;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >>n >> m;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i<n;i++) {
        if(a[i] != a[i+1]) all = 0;
    }
    if(all == 1) {
        cout << n;
        return 0;
    }
    for(int i = 1;i<=n;i++) {
        int t[1000+10], cnt = 0;
        for(int j = i;j<=n;j++) {
            t[++cnt] = a[j];
            if(j == i) continue;
            if(t[j-1] == a[j]) t[1] = a[j], cnt=1;
            else if (cnt >= 2) t[1] = t[2];t[2] = t[3], cnt=2;
        }
        d[t[1]]++;
        if(cnt == 2 && t[1] != t[2]) d[t[2]]++;
    }
    cout << d[a[1]] << " " << d[a[2]] << "\n";
}
