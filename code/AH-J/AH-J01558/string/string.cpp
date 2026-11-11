#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, a, cnt;
char c;
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> c;
        for(int j=1; j<=a; j++) s += c;
    }
    ll len = s.size();
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len - 1 - i]) cnt++;
    }
    cout << cnt;
    return 0;
}
