#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    bool flag = false;
    int n;
    cin >> n;
    string s="";
    int a;
    char c;
    char temp;
    cin >> a >> c;
    temp = c;
    for(int i=1; i<n; i++){
        cin >> a >> c;
        if(c != temp) flag = true;
        while(a--)
            s += c;
    }
    if(!flag) cout << 0;
    long long ans=0;
    for(long long i=0; i<s.size()/2; i++){
        if(s[i] != s[s.size()-i-1])
            ans++;
    }
    cout << ans;
    return 0;
}
