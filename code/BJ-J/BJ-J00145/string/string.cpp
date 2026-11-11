#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, x;
char c;
string s;
long long ans, l, r;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> c;
        for(int i = 1; i <= x; i++){
            s += c;
        }
    }
    if(s.size() % 2 == 1){
        l = s.size() / 2, r = l + 2;
    }else{
        l = s.size() / 2, r = l + 1;
    }
    l--, r--;
    while(l >= 0 && r < s.size()){
        if(s[l] != s[r]){
            ans++;
        }
        l--, r++;
    }
    cout << ans;
    return 0;
}
