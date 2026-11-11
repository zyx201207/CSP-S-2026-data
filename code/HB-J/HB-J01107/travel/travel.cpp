#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r1,x1,r2,x2;
    char r3,x3;
    cin>>r1>>r2>>r3>>x1>>x2>>x3;
    if(r1!=x1){
        cout<<"0000";
        return 0;
    }
    if(r2!=x2){
        cout<<1000;
        return 0;
    }
    if(r3>='A' && r3<='C'){
        if(x3>='A' && x3<='C'){
            if(r3=='B' or x3=='B'){
                cout<<1111;
                return 0;
            }else{
                cout<<1110;
                return 0;
            }
        }else{
            cout<<1100;
            return 0;
        }
    }
    if(r3>='D' && r3<='E'){
        if(x3>='D' && x3<='E'){
            cout<<1111;
            return 0;
        }else{
            cout<<1100;
            return 0;
        }
    }
    return 0;
}
