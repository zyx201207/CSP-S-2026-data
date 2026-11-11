#include <bits/stdc++.h>
using namespace std;
bool hw(string a){
    string x = "",y = "";
    for(long long i = 0;i < a.size();i++){
        x += a[i];
        y += a[a.size()-i];
    }
    if(x == y) return true;
    return false;
}
long long n,cnt = 0;
string s = "";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        long long l;
        char m;
        cin >> l >> m;
        for(long long i = 1;i <= l;i++){
            s += m;
        }
    }
    if(hw(s)){
        cout << 0;
        return 0;
    }
    long long k = s.size();
    for(long long i = 0;i < (k+1)/2;i++){
        if(s[i] != s[k-i-1]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
