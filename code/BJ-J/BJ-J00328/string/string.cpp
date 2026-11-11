#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    int n;
    unsigned long long tmp = 0;
    cin >> n;
    while(n--){
        unsigned long long  x;
        string a;
        cin >> x >> a;
        while(x--){
            s += a;
        }
    }
    string t = s;
    reverse(t.begin(),t.end());
    if(t == s){
        cout << 0 << endl;
        return 0;
    }
    for(unsigned long long i = 0;i <= (s.size() - 2) /2;i++){
        unsigned long long r = s.size() - 1 - i;
        if(s[i] != s[r]) tmp++;
    }
    cout << tmp << endl;
    return 0;
}
