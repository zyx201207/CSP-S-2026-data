#include<bits/stdc++.h>
using namespace std;

bool check(char a,char b){
    if((a == 'A' && b == 'C') || (a == 'C' && b == 'A')) return 1;
    if((a == 'C' && b == 'B') || (a == 'B' && b == 'C')) return 1;
    return 0;
}

int main(){
    freopen("travel.in",stdin,"r");
    freopen("travel.out",stdout,"w");
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";
            bool a,b;
            if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') a = 0;
            else a = 1;
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') b = 0;
            else b = 1;
            if(a == b) {
                cout << "1";
                if(check(s1[2],s2[2])) cout << "0";
                else cout << "1";
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}