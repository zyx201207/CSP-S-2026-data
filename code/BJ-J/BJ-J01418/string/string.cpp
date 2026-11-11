// #include <cstdio>
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, a[200005], cnt=0;
char c[200005];
string total=" ";

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    int len=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
        for(int j=1; j<=a[i]; j++) total += c[i];
        len+=a[i];
    }

    cout << "len: " << len <<", tt: "<< total <<endl;
    for (int i=1; i<=len/2; i++) {
        cout << "i: "<< i <<", n-i+1: " << (n-i+1) <<endl;
        cout << "l: "<< total[i] <<", r: " << total[n-i+1] <<endl;
        if (total[i] != total[n-i+1]) cnt++;
    }
    // for (int i=1; i<=n; i++) {
    //     if (c[i] == c[n-i+1]) {
    //         idx += min(a[i], a[n-i+1]);
    //         if (a[i] > a[n-i+1]) ls = a[i] - a[n-i+1];
    //         if (a[i] < a[n-i+1]) rs = a[n-i+1] - a[i];

    //     }
    // }

    cout << (cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
