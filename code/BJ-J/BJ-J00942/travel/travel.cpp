#include<bits/stdc++.h>
using namespace std;

string a1, b1, a2, b2;
int c1, d1, e1, c2, d2, e2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a1 >> b1 >> a2 >> b2;
    c1 = (a1[0] - '0') * 10 + (a1[1] - '0');
    d1 = (b1[0] - '0') * 10 + (b1[1] - '0');
    e1 = int(b1[2]) - 64;
    c2 = (a2[0] - '0') * 10 + (a2[1] - '0');
    d2 = (b2[0] - '0') * 10 + (b2[1] - '0');
    e2 = int(b2[2]) - 64;
    if(e1 == 6){
        e1--;
    }
    if(e2 == 6){
        e2--;
    }
    if(c1 == c2){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    if(d1 == d2){
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    if((e1 <= 3 && e2 <= 3) || (e1 >= 4 && e2 >= 4)){
        cout << "1";
    }
    else{
        cout << "00";
        return 0;
    }

    if(abs(e1 - e2) == 1){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}