#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans;
string s;
string hw(string s){
    string s1;
    for(int i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }
    return s1;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        string k;
        cin >> k;
        for(int i=1;i<=a;i++){
            s+=k;
        }
    }
    string s1 = hw(s);
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i]) ans++;
    }
    ans/=2;
    cout << ans;
    return 0;
}
