#include <bits/stdc++.h>
using namespace std;
long long n;
string s = {};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long x;
    char c;
    while(n--){
        cin >> x;
        cin >> c;
        for(int i = 1; i <= x; i++){
            s += c;
        }
    }
    long long cnt = 0 , lenm = s.size();
    int len = (lenm + 1) / 2;
    for(int i = 0; i < len; i++){
        if(s[i] != s[len - 1 - i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
