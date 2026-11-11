#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s = "",t;
    for(int i = 1;i <= n;i++){
        int num;
        string c;
        cin >> num >> c;
        for(int i = 1;i <= num;i++){
            s += c;
        }
    }
    t = s;
    reverse(t.begin(),t.end());
    int cnt = 0;
    for(int i = 0;i <= t.size();i++){
        if(t[i] != s[i]){
            cnt++;
            t[i] = s[i];
            s[s.size()-i-1] = s[i];
        }
    }
    cout << cnt;
    return 0;
}
