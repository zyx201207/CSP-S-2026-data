#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    if(s1 == s2) cout << "1";
    else cout << "0";
    if(c1[0] == c2[0] && c1[1] == c2[1] && s1 == s2) cout << "1";
    else cout << "0";
    char r1 = c1[2],r2 = c2[2];
    bool f = false;
    if(s1 == s2 && c1[0] == c2[0] && c1[1] == c2[1]){
        if(r1 == 'D' && r2 == 'F') f = true;
        else if(r1 == 'F' && r2 == 'D') f = true;
        else if(r1 >= 'A' && r1 <= 'C' && r2 >= 'A' && r2 <= 'C')f = true;
    }
    if(f) cout << "1";
    else cout << "0";
    if(f){
        if((int)abs(r2 - r1) == 1) cout << "1";
        else cout << "0";
    }else{
        cout << "0";
    }
    return 0;
}
