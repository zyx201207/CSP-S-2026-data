#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s = "";
    string s2 = "";
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (long long i = 1;i <= n;i++){
        long long x;
        cin >> x;
        string a = "";
        cin >> a;
        for (int i = 1;i <= x;i++){
            s += a;
        }
    }
    for (long long i = 0;i < s.size() - 1;i++){
        s2[i] = s[s.size()-1];
    }
    long long sum = 0;
    for (long long i = 0;i < (s.size() - 1) / 2;i++){
        if (s[i] != s2[i]){
            sum ++;
        }
    }
    cout << sum;
    return 0;
}