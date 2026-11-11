#include<iostream>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int sc, sr, xc, xr;
    char sn, xn;
    cin>>sc>>sr>>sn>>xc>>xr>>xn;
    if (sc == xc){
        cout<<"1";
        if (sr == xr){
            cout<<"1";
            if (sn == 'A' && xn == 'B' || sn == 'A' && xn == 'C' || sn == 'B' && xn == 'C' || sn == 'B' && xn == 'A' || sn == 'C' && xn == 'A' || sn == 'C' && xn == 'B' || sn == 'D' && xn == 'F' || sn == 'F' || xn == 'D'){
                cout<<"1";
                if (sn == 'A' && xn == 'B' || sn == 'B' && xn == 'C' || sn == 'B' && xn == 'A' || sn == 'C' && xn == 'B' || sn == 'D' && xn == 'F' || sn == 'F' || xn == 'D'){
                    cout<<"1";
                } else {
                    cout<<"0";
                }
            } else {
                cout<<"00";
            }
        } else {
            cout<<"000";
        }
    } else {
        cout<<"0000";
    }
    return 0;
}
