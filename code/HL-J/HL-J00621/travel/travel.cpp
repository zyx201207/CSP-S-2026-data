#include<bits/stdc++.h>
using namespace std;
int main(){
    string a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1[0]==a2[0]&&a1[1]==a2[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(b1[1]==b2[1]&&b1[0]==b1[0]){
        cout<<1;
        if(b1[2]<='C'&&b2[2]<='C'){
            cout<<1;
        }
        else if(b1[2]>'C'&&b2[2]>'C'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0<<0;
    }
    if(b1[2]+1==b2[2]||b1[2]-1==b2[2]+1){
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
