#include<bits/stdc++.h>
using namespace std;
int cr,cx,zr,zx;
char br,bx;
bool ff=1,f=1,fff=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>zr>>br;
    cin>>cx>>zx>>bx;
    if(cr==cx){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }

    if(zr==zx){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }

    if(ff){
        if((br<='C'&&bx<='C')||(br>='D'&&bx>='D')){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
        f=0;
    }

    if(f){
        if(abs((br-'A')-(bx-'A'))==1){
            if((br=='C'&&bx=='D')||(br=='D'&&bx=='C')){
                cout<<0;
            }else{
                cout<<1;
            }
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
