#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s = "";
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        long long a;
        char b;
        cin >> a >> b;
        for(int j = 1;j <= a;j++){
            s.push_back(b);
        }
    }
    string s1 = "";
    for(int i = s.size() - 1;i >= 0;i--){
        s1.push_back(s[i]);
    }

    int cnt = 0;
    for(int i = 0;i <= s.size();i++){
        if(s[i] != s1[i]){
            s1[i] = s[i];
            s[s.size() - 1 - i] = s1[i];
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
