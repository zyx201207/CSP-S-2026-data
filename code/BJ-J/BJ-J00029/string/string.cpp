#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 2e5 + 10;
int n;
ull a[N];
char c[N];
string s;
ull cnt;
ull len = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i] >> c[i];
        len += a[i];
        for(int j = 1;j <= a[i]; j++){
            s.push_back(c[i]);
        }
    }
    s = " " + s;
    ull l = 1, r = len;
    while(l <= r){
        if(s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}
