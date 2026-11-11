#include<bits/stdc++.h>
using namespace std;
long long a[200005]
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    string s = 0;
    for(int i = 1;i <= n;i++){
        s += a[i] * c[i];
    }
    string b =0;
    while(s.length() != 0){
        for(int z = s.length();z > 0;z--){
            b += s[z];
        }
    }
    int cnt = 0;
    if(s == b) cout << 0;
    else{
        for(int j = 0;j < s.length();j++){
            if(b[j] == s[j]) j++;
            else{
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}
