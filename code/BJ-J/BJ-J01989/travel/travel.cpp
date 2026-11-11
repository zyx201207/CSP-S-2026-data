#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,xc;
    string rz,xz;
    int sign2 = 0;
    int sign3 = 0;
    int sign4 = 0;
    cin >> rc >> rz >> xc >> xz;
    if(rc == xc){
        cout << 1;
    }
    else {
        cout << 0;
    }
    if(rc == xc&&rz[0] == xz[0]&&rz[1] == xz[1]){
        cout << 1;
        sign2 = 1;
    }
    else{
        cout << 0;
    }
    if(sign2 == 1&&rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C'){
        cout << 1;
        sign3 =1;
    }
    else if(sign2 == 1&&rz[2]>='D'&&rz[2]<='F'&&xz[2]>='D'&&xz[2]<='F'){
        cout << 1;
        sign4 = 1;
    }
    else{
        cout << 0;
    }
    if(sign3 == 1){
        int a = rz[2];
        int b = xz[2];
        if(abs(a-b) == 1){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else if(sign4 == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
