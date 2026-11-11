#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rx,rz,xx,xz;
    cin>>rx>>rz>>xx>>xz;
    if(rx == xx){
        cout<<"1";
    }
    else {
    cout <<"0";}
    if(rz[0] == xz[0] && rz[1]==xz[1]){
        cout << "1";
        }
        else {
        cout <<"0";
        }
    if(rz[2] == xz[2]){
        cout<< "1";
    }
    else{
        cout <<"0";}

    return 0;
}
