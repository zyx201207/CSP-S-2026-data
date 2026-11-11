#include <bits/stdc++.h>
using namespace std;

string S;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    char c,X,Y;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x >> c;
        for (int j = 1;j <= x;j++) {
        S += c;
        }
    }
    for (int i = x;i >= 1;i--) {
        X += S[i];
    } for (int i = 1;i <= x;i++) {
        Y += S[i];
    }
    if (X == Y){
        cout << "0";
    }
    return 0;
}
