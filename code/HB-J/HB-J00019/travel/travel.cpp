#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;

    if((s1[1] == s2[1] && s1[0] == s2[0]) && (c1 == c2)) cout << 1;
    else cout << 0;

    char a = s1[2];
    char b = s2[2];
    bool ce1,ce2; // false ABC true DE
    if(a == 'A' || a == 'B' || a == 'C'){
        ce1 = false;
    }
    else{
        ce1 = true;
    }
    if(b == 'A' || b == 'B' || b == 'C'){
        ce2 = false;
    }
    else{
        ce2 = true;
    }
    if(ce1 == ce2 && (c1 == c2) && (s1[1] == s2[1] && s1[0] == s2[0])) cout << 1;
    else cout << 0;

    if((ce1 == ce2) && abs((int)a - (int)b) == 1 && (c1 == c2) && (s1[1] == s2[1] && s1[0] == s2[0])) cout << 1;
    else cout << 0;

    return 0;

}
