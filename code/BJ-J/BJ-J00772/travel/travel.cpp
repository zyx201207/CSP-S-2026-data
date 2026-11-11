#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin >> a >> b >> c >> d;

    string s1=""; s1+=b[0]; s1+=b[1];
    string s2=""; s2+=d[0]; s2+=d[1];

    if(a!=c) {
        cout << "0000";
        return 0;
    }
    cout << "1";

    if(s1!=s2) {
        cout << "000";
        return 0;
    }
    cout << "1";

    if((b[2]=='A'&&d[2]=='B') || (b[2]=='B'&&d[2]=='A') || (b[2]=='A'&&d[2]=='C') || (b[2]=='C'&&d[2]=='A') || (b[2]=='B'&&d[2]=='C') || (b[2]=='C'&&d[2]=='B') || (b[2]=='D'&&d[2]=='F') || (b[2]=='F'&&d[2]=='D')) {
        cout << "1";
    }
    else {
        cout << "00";
        return 0;
    }

    if((b[2]=='A'&&d[2]=='B') || (b[2]=='B'&&d[2]=='A') || (b[2]=='B'&&d[2]=='C') || (b[2]=='C'&&d[2]=='B') || (b[2]=='D'&&d[2]=='F') || (b[2]=='F'&&d[2]=='D')) {
        cout << "1";
    }
    else {
        cout << "0";
        return 0;
    }


    return 0;
}
