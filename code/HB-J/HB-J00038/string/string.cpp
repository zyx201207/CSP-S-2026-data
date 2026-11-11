#include <bits/stdc++.h>
using namespace std;
int n,pos;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        char c;
        for (int j = 1; j <= a; j++){
            s+=c;
        }
    }
    for (int i = 0; i <= n/2; i++){
        if (s[i]!=s[n-i-1]){
            pos++;
        }
    }
    cout << pos;
    return 0;
}
