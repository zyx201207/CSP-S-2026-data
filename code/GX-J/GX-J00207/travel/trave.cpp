#include <iostream>
using namespace std;

int main(){
    int x,l,z,o,t;
    int c[o];
    int y[t];
    cin >> x >> c[o]>> l >> y[t];
    if(x == l){
        z=1000;
        if(c[0]==y[0]){
            z=1100;
            if(c[1]==y[1]){
                z=1110;
                if(c[2]+1==y[2]){
                    z=1111;
                    cout << z;
                }
            }
            else{
                cout << z;
            }
        }
        else{
            cout << z;
        }
    }
    else{
        z=0000;
        cout << z;
    }




















return 0;
}
