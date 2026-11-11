#include <bits/stdc++.h>
using namespace std;
bool check(char a, char b){
    if(a == 'A' && b == 'B')
        return true;
    if(a == 'B' && (b == 'A' || b == 'c'))
        return true;
    if(a == 'C' && b == 'B')
        return true;
    if(a == 'D' && b == 'F')
       return true;
    if(a == 'F' && b == 'D')
        return true;
    return false;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    string l1 = "", l2 = "";
    char p1, p2;
    for(int i=0; i<2; i++){
        l1 += s1[i];
    }
    p1 = s1[2];
    for(int i=0; i<2; i++){
        l2 += s2[i];
    }
    p2 = s2[2];
    if(l1 == l2) cout << 1;
    else{
        cout << "000";
        return 0;
    }
    if((p1 == 'A' || p1 == 'B' || p1 == 'C') && (p2 == 'A' || p2 == 'B' || p2 == 'C')) cout << 1;
    else if((p1 == 'D' || p1 == 'F') && (p2 == 'D' || p2 == 'F') ) cout << 1;
    else{
        cout << "00";
        return 0;
    }
    if(check(p1, p2)){
        cout << 1;
        return 0;
    }else{
        cout << 0;
        return 0;
    }
    return 0;
}
