#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long L;
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int lin;
    char c;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> lin >> c;
        for (int j = 0 ; j < lin ; j++) 
            s += c;
    }

    L = s.size();

    for(long long i = 0; i < L / 2; i++){
        if(s[i] != s[L - i - 1]) ans++;
    }

    cout << ans;
    return 0;
}