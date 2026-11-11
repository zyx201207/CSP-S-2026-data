# include <bits/stdc++.h>
using namespace std;
long long n, m, a[500001], book[500001], cnt[500001];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            if(book[a[j]] == 0)
                book[a[j]] = 1;
            else {
                for(int k = j;k >= 1;k--)
                    book[a[k]] = 0;
            }
            book[a[j]] = 1;
        }
        for(int j = 1;j <= m;j++) {
            if(book[j] == 1)
                cnt[j]++;
        }
        for(int j = 1;j <= m;j++)
            book[j] = 0;
    }
    for(int i = 1;i <= m;i++) {
        if(cnt[i] != 0)
            cout << cnt[i] << " ";
    }
    return 0;
}
