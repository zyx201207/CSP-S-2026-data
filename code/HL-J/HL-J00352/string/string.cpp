#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    string s = "";
    while(T--){
        int num;
        string ns;
        cin >> num >> ns;
        while(num--){
            s += ns;
        }
    }
    int ans = 0;
    for(int i = 0;i < s.size()/2+1;i++){
        if(s[i] != s[s.size()-1-i]){
            s[i] = s[s.size()-1-i] = s[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}