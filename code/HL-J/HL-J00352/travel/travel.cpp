#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string z1, z2;
    cin >> c1 >> z1 >> c2 >> z2;
    if(c1 == c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    string p1, p2;
    p1 = z1.substr(0, 2);
    p2 = z2.substr(0, 2);
    if(p1 == p2){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    z1.erase(0, 2);
    z2.erase(0, 2);
    if((z1[0] >= 'A' && z1[0] <= 'C' && z2[0] <= 'C' && z2[0] >= 'A') || (z1[0] >= 'D' && z1[0] <= 'F' && z2[0] >= 'D' && z2[0] <= 'F')){
        cout << 1;
    }else{
        cout << "00";
        return 0;
    }
    if(
        ( z1[0] == 'A' && z2[0] == 'B' ) ||
        ( z1[0] == 'B' && z2[0] == 'A' ) ||
        ( z1[0] == 'B' && z2[0] == 'C' ) ||
        ( z1[0] == 'C' && z2[0] == 'B' ) ||
        ( z1[0] == 'D' && z2[0] == 'F' ) ||
        ( z1[0] == 'F' && z2[0] == 'D' )
    ){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}