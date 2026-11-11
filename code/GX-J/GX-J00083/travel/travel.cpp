#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in" , "r", stdin);
    freopen("travel.out" , "w", stdout);
    string R,X;
    char r[3],x[3];
    cin >> R >> r >> X >> x;
    if(R!=X){
        cout<<"0000";
        return 0 ;
    }
    else if (r[0] != x[0] || r[1] != x[1]){
        cout<<"1000";
        return 0;
    }
    else if(r[2] == 'A' || r[2] == 'B' || r[2] == 'C'){
        if(x[2] != 'A' && x[2] != 'B' && x[2] != 'C'){
            cout<<"1100";
        }
        else if(r[2] == 'A' && x[2] == 'C'){
            cout<<"1110";
        }
        else if(r[2] == 'C' && x[2] == 'A'){
            cout<<"1110";
        }
        else{
           cout<<"1111";
        }
        return 0;
    }
    else if(r[2] == 'D' || r[2] == 'F'){
        if(x[2] != 'D' && x[2] != 'F'){
            cout<<"1100";
        }
        else{
           cout<<"1111";
        }
        return 0;
    }
    return 0 ;
}
