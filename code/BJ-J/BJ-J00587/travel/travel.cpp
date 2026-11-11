#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

string c1, s1, c2, s2;

bool sc, sr;
int sp;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2){
        cout << 1;
        sc = 1;
    }
    else{
        cout << 0;
    }

    if(sc && s1[0] == s2[0] && s1[1] == s2[1]){
        cout << 1;
        sr = 1;
    }
    else{
        cout << 0;
    }

    if(sc && sr){
        if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                cout << 1;
                sp = 1;
            }
            else{
                cout << 0;
            }
        }
        else if(s1[2] == 'D' || s1[2] == 'F'){
            if(s2[2] == 'D' || s2[2] == 'F'){
                cout << 1;
                sp = 2;
            }
            else{
                cout << 0;
            }
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }

    if(sc && sr && sp){
        if(sp == 1){
            if(abs(s1[2] - s2[2]) == 1){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        else{
            cout << 1;
        }
    }
    else{
        cout << 0;
    }

    return 0;
}
