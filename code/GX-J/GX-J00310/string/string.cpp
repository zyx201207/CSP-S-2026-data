#include<bits/stdc++.h>
using namespace std;
string s = "";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, a, c = 0;
    string sn;
    cin >> n;
    for (int i = 1;i<=n;i++){
        cin >> a >> sn;
        for (int j = 1;j<=a;j++){
            s += sn;
        }

    }
    for (int k = 1;k<=s.length();k++){
        if (s[k-1] != s[s.length()-k] && k-1 <= s.length()-k){
            c++;
        }
    }
    cout << c;
    return 0;
}
