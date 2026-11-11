#include "bits/stdc++.h"
using namespace std;

string s = "";

int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        while(a--) {
            s += c;
        }
    }
    int res = 0;

    for(int i = i, j = s.size() - 1; i <= j; i++,j--) {
        if(s[i] != s[j]) {
            res++;
        }
    }
    cout <<res;


    return 0;
}
