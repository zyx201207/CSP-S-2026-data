#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string r1,x1,r,x;
    cin >> r1 >> r >> x1 >> x;
    if (r1[0] != x1[0] or r1[1] != x1[1]){
        cout << "0000";
        return 0;
    }
    else {
        cout << "1";
    }
    if (r[0] == x[0] and r[1] == x[1]){
        cout << "1";
    }
    else {
        cout << "000";
        return 0;
    }
    if (r[2] >= 'A' and r[2] <= 'C' and x[2] >= 'A' and x[2] <= 'C'){
        cout << "1";
    }

    else if(r[2] >= 'D' and r[2] <= 'E' and x[2] >= 'D' and x[2] <= 'E'){
        cout << "1";
    }
    else {
        cout << "00";
        return 0;
    }
    if (r[2] == 'A' and x[2] == 'B' or r[2] == 'B' and x[2] == 'A'){
        cout << "1";
    }
    else if(r[2] == 'C' and x[2] == 'B' or r[2] == 'B' and x[2] == 'C'){
        cout << "1";
    }
    else if(r[2] == 'D' and x[2] == 'E' or r[2] == 'E' and x[2] == 'D'){
        cout << "1";
    }
    else {
        cout << "0";
        return 0;
    }
    return 0;
}
