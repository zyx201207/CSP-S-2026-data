#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[10000005];
string s[10000005];
string b="";
string c="";
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i] >> s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=a[i]; j++){
            b += s[i];
        }
    }
    for(int i=n; i>0; i--){
        for(int j=1; j<=a[i-1]; j++)
            c += s[i-1];
        }
    if(b==c)
        cout << "0";
    else
        cout << "2";
    return 0;
}


