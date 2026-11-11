#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,a,b;
    cin >> c >> s>> a >> b;
    if (c == a){
        cout << 1;
    } else {
    cout << 0;
    }
    if(s[0] == b[0] && b[1] == s[1]){
        cout << 1;
    } else {
        cout << 0;
    }
    if((s[2] =='A' && b[2] == 'B') || (s[2] == 'B' && b[2] == 'C') || (s[2] =='D'&& b[2] == 'E') || (s[2] == 'A' && b[2] == 'C')){
        cout << 1;
    } else {
        cout << 0;
    }
    if((s[2] =='A' && b[2] == 'B') || (s[2] == 'B' && b[2] == 'C') || (s[2] =='D'&& b[2] == 'E')){
            cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
