#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xa,ya,xb,yb;
    cin >> xa >> ya;
    cin >> xb >> yb;
    string yes = "";
    if(xa == xb){
        yes.push_back('1');
    }
    else{
        yes.push_back('0');
        yes.push_back('0');
        yes.push_back('0');
        yes.push_back('0');
        cout << yes;
        return 0;
    }

    if(ya[0] == yb[0] && ya[1] == yb[1]){
        yes.push_back('1');
    }
    else{
        yes.push_back('0');
        yes.push_back('0');
        yes.push_back('0');
        cout << yes;
        return 0;
    }
    char n = ya[2],m = yb[2];
    if(n <= 'c' && m <= 'C'){
        yes.push_back('1');
    }
    else{
        if(n >= 'D' && m >= 'D'){
            yes.push_back('1');
        }
        else{
            yes.push_back('0');
            yes.push_back('0');
            cout << yes;
            return 0;
        }
    }

    if(abs(ya[2] - yb[2]) == 1){
        yes.push_back('1');
    }
    else{
        if(ya[2] == 'D' && yb[2] == 'F'){
            yes.push_back('1');
        }
        else{
            yes.push_back('0');
        }
    }

    cout << yes;
    return 0;
}
