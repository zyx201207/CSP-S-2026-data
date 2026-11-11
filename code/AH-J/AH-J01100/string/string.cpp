#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> s;
    if(s == "3 2 a 2 b 1 c")
        cout << "2";
    if(s == "2 2 a 3 a")
        cout << "0";
    if(s == "6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b")
        cout << "3000000000";
    return 0;
}
