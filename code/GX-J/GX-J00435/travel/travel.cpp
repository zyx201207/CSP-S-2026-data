#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
string a1, b1, a2, b2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a==c){
        cout << "1";
    }
    else{
        cout << "0";
    }
    a1 = b[0]+b[1];
    b1 = d[0]+d[1];
    if(a==c && a1 == b1){
        cout << "1";
    }
    else{
        cout << "0";
    }
    a2 = b[2];
    b2 = d[2];
    if(a==c && a1 == b1 && (a2=="A" && b2=="B" || a2=="A" && b2=="C" || a2=="C" && b2=="A" || a2=="B" && b2=="C" || a2=="C" && b2=="B" || a2=="B" && b2=="A" || a2=="D" && b2=="F" || a2=="F" && b2=="D")){
        cout << "1";}
    else{
        cout << "0";}
    if(a==c && a1 == b1 && (a2=="A" && b2=="B" || a2=="B" && b2=="C" || a2=="B" && b2=="A" || a2=="C" && b2=="B" || a2=="D" && b2=="F" || a2=="F" && b2=="D")){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
