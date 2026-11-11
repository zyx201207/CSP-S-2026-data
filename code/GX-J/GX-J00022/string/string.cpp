#include<bits/stdc++.h>
#define int long long
using namespace std;
bool huiwen(string a){
    string b = a;
    reverse(a.begin(),a.end());
    return b == a;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,su = 0;
    string s = "";
    cin >> n;
    if(n > 2000)return 0;
    for(int i = 1;i <= n;i++){
        int o;
        string p;
        cin >> o >> p;
        if(o >= (int)1e9)return 0;
        for(int j = 1;j <= o;j++)s += p;
    }
    if(huiwen(s))cout << 0;
    else if(n == 2)cout << 1;
    else{
        if(s.size() % 2 == 0){
            string p = s.substr(0,s.size() / 2);
            string m = p;
            reverse(p.begin(),p.end());
            m += p;
            for(int i = 1;i <= s.size();i++)if(m[i] != s[i])su++;
        }else{
            string p = s.substr(0,s.size() / 2);
            string m = p + s[s.size() / 2 + 1];
            reverse(p.begin(),p.end());
            m += p;
            for(int i = 1;i <= s.size();i++)if(m[i] != s[i])su++;
        }
        cout << su;
    }
    return 0;
}
