#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int a, n, cnt=0; char c;
    cin >> n;
    while(n--){
        cin >> a >> c;
        while(a--){
            s.push_back(c);
        }
    }
    int sz = s.size();
    for (int i=0;i<sz/2;i++){
        if (s[i] != s[sz-i]) cnt++;
    }
    cout << cnt;

    return 0;
}
