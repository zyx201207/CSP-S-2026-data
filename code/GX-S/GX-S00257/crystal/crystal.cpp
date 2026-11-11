#include <bits/stdc++.h>
#define QAQ return 0

using namespace std;
int n;
long long m, a[500000], sum[5000][5001], fin[5001], tmp[5000], number[201];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> a[0] >> a[1];
    bool flag = true;
    long long value = a[1] - a[0];
    // cout << value << ' ';
    
    for (int i = 2; i < n; i++) {
        cin >> a[i];
        if (a[i] - a[i - 1] != value) flag = false;
        // cout << a[i] - a[i - 1] << ' ';
    }
    // cout << '\n' << flag << '\n';
    
    sort(a, a + n);
    if (flag) {
        int cnt = 0, sum = 0, step = 0;
        while (cnt < n) {
            cnt++;
            if (cnt % 2 == 1) {
                step += value;
            }
            if (sum + step > m) break;
            sum += step;
            // cout << step << ' ';
        }
        // cout << '\n';
        cout << cnt << '\n';
    }
    else if (n <= 5000) {
        for (int i = 0; i < n; i++) {
            int cnt1 = 0, cnt2 = 1, cnt3 = 0;
            while (true) {
                if (i + cnt1 < n) {
                    if (i - cnt2 < 0) {
                        sum[i][cnt3 + 1] = sum[i][cnt3] + a[i + cnt1] - a[i];
                        cnt1++;
                        cnt3++;
                    }
                    else if (a[i + cnt1] - a[i] <= a[i] - a[i - cnt2]) {
                        sum[i][cnt3 + 1] = sum[i][cnt3] + a[i + cnt1] - a[i];
                        cnt1++;
                        cnt3++;
                    }
                    else {
                        sum[i][cnt3 + 1] = sum[i][cnt3] + a[i] - a[i - cnt2];
                        cnt2++;
                        cnt3++;
                    }
                }
                else {
                    if (i - cnt2 >= 0) {
                        sum[i][cnt3 + 1] = sum[i][cnt3] + a[i] - a[i - cnt2];
                        cnt2++;
                        cnt3++;
                    }
                    else break;
                }
                // cout << sum[i][cnt3] << " ";
            }
            // cout << "\n";
        }
        for (int i = 1; i <= n; i++) {
            fin[i] = 1000000001;
            for (int j = 0; j < n; j++) {
                fin[i] = min(fin[i], sum[j][i]);
            }
            if (fin[i] > m) {
                cout << i - 1 << '\n';
                QAQ;
            }
            // cout << fin[i] << ' ';
        }
        // cout << '\n';
        cout << "5000\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            number[a[i] + 100]++;
        }
        for (int i = -100; i <= 100; i++) {
            int cnt = 2;
            sum[i + 100][1] = 0;
            for (int j = 1; j <= 200; j++) {
                if (i + j <= 100) {
                    if (i - j < 200) {
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i + j + 100] * j;
                        cnt++;
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i - j + 100] * j;
                        cnt++;
                    }
                    else if (number[i + j + 100] >= number[i - j + 100]) {
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i + j + 100] * j;
                        cnt++;
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i - j + 100] * j;
                        cnt++;
                    }
                    else {
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i - j + 100] * j;
                        cnt++;
                        sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i + j + 100] * j;
                        cnt++;
                    }
                }
                else {
                    sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i - j + 100] * j;
                    cnt++;
                    sum[i + 100][cnt] = sum[i + 100][cnt - 1] + number[i + j + 100] * j;
                    cnt++;
                }
            }
        }
        for (int i = 1; i <= 201; i++) {
            fin[i] = 1000000001;
            for (int j = 0; j <= 200; j++) {
                fin[i] = min(fin[i], sum[j][i]);
            }
            if (fin[i] > m) {
                cout << i - 1 << '\n';
                QAQ;
            }
            // cout << fin[i] << ' ';
        }
    }
    
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
    QAQ;
}
