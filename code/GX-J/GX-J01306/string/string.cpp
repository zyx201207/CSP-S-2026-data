#include <bits/stdc++.h>
using namespace std;
string s;
char ch;
long long n, num, sp = 1;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++){
        long long x;
        cin >> x >> ch;
        for (long long j = sp; j <= sp + x - 1; j++){
            s[j] = ch;
        }
        sp = sp + x;
    }
    sp--;
    for (long long i = 1; i <= sp/2; i++){
        if (s[i] != s[sp + 1 - i]){
            s[sp + 1 - i] = s[i];
            num++;
        }
    }
    cout << num;
    return 0;
}
