#include <bits/stdc++.h>
using namespace std;
struct zw{
    int cx;
    string zuow ;
};
zw r , x;
void bd(zw a,zw b){
    if(a.cx == b.cx){
        cout << 1 ;
    }
    else{
        cout << 0;
    }
    if(a.cx == b.cx&&a.zuow[0]==b.zuow[0]&& a.zuow[1] == b.zuow[1]){
        cout << 1;
    }
    else {
        cout << 0;
    }
    if(a.cx == b.cx&&a.zuow[0]==b.zuow[0]&& a.zuow[1] == b.zuow[1]){
        if(a.zuow[2]>='A'&&a.zuow[2]<='C'&& b.zuow[2]>='A' && b.zuow[2] <= 'C'){
            cout << 1 ;
            if (abs(a.zuow[2] - b.zuow[2]) == 1){
                cout << 1;
            }
            else{
                //cout <<abs(a.zuow[2] - b.zuow[2]) << endl;
                cout << 0;
            }
        }
        else if(a.zuow[2] == 'D' && b.zuow[2] == 'F' || a.zuow[2]== 'F' && b.zuow[2]== 'D'){
            cout << 1 << 1;
        }
        else {
            cout << 0 <<0;
        }
    }
    else {
        cout << 0 << 0 ;
    }
}
int main(){
    freopen("travel.in" , "r" , stdin) ;
    freopen("travel.out" , "w" , stdout) ;
    cin >> r.cx>> r.zuow >> x.cx>> x.zuow;
    bd(r , x) ;
    return 0 ;
}
