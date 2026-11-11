#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int b;

bool cmp(int x, int y){
    int m = (1 << b) - 1;
    return (x & m) > (y & m);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    int a[N];
    cin >> n >> m;

    int maxa = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    if(m == 1) {
        cout << maxa;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    int len = 0;
    while(maxa > 0) {
        maxa >>= 1;
        len++;
    }
    int cnt;
    int ans = 0;
    for(int i = len; i >= 1; i--) {
        cnt = 0;
        for(int j = 1; j <= n; j++)
            cnt += (a[j] >> (i - 1)) & 1;

        if(cnt >= m) {
            b = i;
            sort(a + 1, a + n, cmp);
            int time = 0;
            for(int j = 1; j <= n; j++) {
                if ((a[j] >> (i - 1)) & 1) {
                    time++;
                    if (ans == 0)
                        ans = a[j];
                    else
                        ans &= a[j];
                }
                if(time >= m) break;
            }
            break;
        }
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
