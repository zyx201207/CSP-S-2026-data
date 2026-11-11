#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    int a2,b2;
    char a3,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    if(a1==b1){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(a2==b2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(a3<='C'&&b3<='C'||a3>='D'&&b3>='D'){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(a3<='C'&&b3<='C'){
        if(a3=='B'||b3=='B'){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"1";
    }
    return 0;
}
