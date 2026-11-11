#include <bits/stdc++.h>
using namespace std;
void num(long long a,char b,string &s){
    for(int i = 0;i<a;i++){
        s += b;
    }
}
int main(){
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt = 0;
    string s = "";
    cin >> n;
    for(int i = 0;i<n;i++){
        long long a;
        char b;
        cin >> a >> b;
        num(a,b,s);
    }
    string c = s;
    reverse(c.begin(),c.end());
    if(c == s){
        cout << 0;
        return 0;
    }
    for(int i = 0;i<n;i++){
        if(s[i] != c[i]){
            cnt ++;
        }
    }
    cout <<cnt;
}
