#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
int n, cntt;
int a[N+5];
char c[N+5];
string s;
double cnnt;
int sum;

int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
        cntt+=a[i];
    }
    int AA=1;
    while (cntt == s.size()) {
        for (int i=1; i<=a[AA]; i++) {
            s+=c[AA];
        }
        AA++;
    }
    cnnt=cntt;
    for (int i=1; i<=ceil(cnnt/2); i++) {
        if (s[i]!=s[cntt-i+1]) {
            sum++;
        }
    }
    cout << sum;

    return 0;
}