#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long len, len1, sum;
string s, s1, s2;
char ch;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        cin >> n >> ch;
        for(int j = 1; j <= n; j++){
            s += ch;
        }
    }
    len = s.size();
    if(len % 2 == 0) len1 = len / 2;
    else len1 = len / 2 + 1;
    for(int i = 0; i < len1; i++){
        s1 += s[i];
        s2 += s[len - 1 - i];
    }
    for(int i = 0; i < len1; i++){
        if(s1[i] != s2[i]){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
