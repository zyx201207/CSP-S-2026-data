#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int A1,B1;
    string A2,B2;

    cin >> A1 >> A2 >> B1 >> B2;

    int Al,Bl,Ar,Br;

    Al = (A2[0] - '0') * 10 + (A2[1] - '0');
    Ar = (A2[2] - 'A');
    Bl = (B2[0] - '0') * 10 + (B2[1] - '0');
    Br = (B2[2] - 'A');

    if(A1 == B1){
        cout << '1';
    }else{
        cout << "0000";
        return 0;
    }
    if(Al == Bl){
        cout << '1';
    }else{
        cout << "000";
        return 0;
    }
    if(((Ar <= 2) && (Br <= 2)) || ((Ar > 2) && (Br > 2))){
        cout << '1';
    }else{
        cout << "00";
        return 0;
    }

    bool l,r;

    l = (Al == Bl) && ((Ar + 1 == Br) || (Ar - 1 == Br));
    r = (Ar == Br) && (((Al + 1) == Bl) || ((Al - 1) == Bl));

    if(l || r){
        cout << '1';
    }else{
        cout << "0";
        return 0;
    }

    return 0;
}
