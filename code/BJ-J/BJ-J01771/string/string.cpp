#include<bits/stdc++.h>
using namespace std;
int n, sa[200005], cnt;
string s;
int main(){
    cin >> n;
    sa[0] = 1;
    for(int i = 1; i <= n; i++){
        int a;
        char c;
        cin >> a >> c;
        sa[i] = sa[i-1]+a+1;
        for(int j = sa[i-1]; j <= sa[i]; j++){
            s += c;
        }
    }
    int siz = s.size();
    for(int i = 1; i <= siz/2; i++){
        if(s[i] != s[siz-i+1]) cnt++;
    }
    cout << cnt;
}
