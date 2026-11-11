#include <bits/stdc++.h>
using namespace std;
int n, t,ans;
char c;
string s;
int main(){
    freopen("string.in" , "r" ,stdin);
    freopen("string.out" , "w" ,stdout);
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> t >> c;
        for(int j = 1; j<= t ; j++){
            s += c;
        }
    }
    int l,r;
    if(s.length()%2==0){
        r = s.length()/2;
        l = r -1;
    }
    else{
        r = s.length() /2+ 1;
        l = r - 2;
    }
    while(l>= 0 && r <= s.length()-1){
        if(s[l] != s[r]) ans++;
        l--, r++;
    }
    cout << ans << endl;
    return 0;
}
