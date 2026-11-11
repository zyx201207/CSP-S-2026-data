#include<bits/stdc++.h>
using namespace std;

string rc, rs, xc, xs;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> rc >> rs >> xc >> xs;

    if(rc == xc){ // check ans 1
        cout << 1;
    }
    else{
        cout << 0;
    }

    int r_pai = (rs[1] - '0') + (rs[0] - '0') * 10;
    int x_pai = (xs[1] - '0') + (xs[0] - '0') * 10;
    if(rc == xc && r_pai == x_pai){ // check ans 2
        cout << 1;
    }
    else{
        cout << 0;
    }


    char r_ce = rs[2];
    char x_ce = xs[2];
    if(rc == xc && r_pai == x_pai && (r_ce >= 'D' && x_ce >= 'D' || r_ce <= 'C' && x_ce <= 'C')){ // check ans 3
        cout << 1;
    }
    else{
        cout << 0;
    }


    if(rc == xc && r_pai == x_pai && (r_ce >= 'D' && x_ce >= 'D' || r_ce <= 'C' && x_ce <= 'C') && abs(r_ce - x_ce) == 1){ // check ans 4
        cout << 1;
    }
    else{
        cout << 0;
    }


    return 0;
}
