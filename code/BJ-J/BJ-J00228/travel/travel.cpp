#include<bits/stdc++.h>
using namespace std;
string check_side(char a){
    if(a >= 'A' && a <= 'C') return "left";
    else if(a == 'D' || a == 'F') return "right";
    else return "error";
}
bool check(char x, char y){
    int num_x, num_y;
    if(x == 'F') num_x = 4;
    else num_x = x - 'A';
    if(y == 'F') num_y = 4;
    else num_y = y - 'A';
    return abs(num_x - num_y) == 1;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    char n1, n2;
    cin >> c1 >> s1 >> c2 >> s2;
    n1 = s1[2];
    n2 = s2[2];
    s1 = s1.substr(0, 2);
    s2 = s2.substr(0, 2);
    if(c1 != c2){
        cout << "0000" << endl;
        return 0;
    }
    else if(s1 != s2){
        cout << "1000" << endl;
        return 0;
    }
    else if(check_side(n1) != check_side(n2)){
        cout << "1100" << endl;
        return 0;
    }
    else if(check(n1, n2) == false){
        cout << "1110" << endl;
        return 0;
    }
    else{
        cout << "1111" << endl;
        return 0;
    }
    return 0;
}
