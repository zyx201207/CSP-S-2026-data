#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char ax,bx;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel1.out","w",stdout);
    cin>>a>>c;
	cin>>ax;
	cin>>b>>d;
	cin>>bx;
    if(a==b){
        cout<<"1";
        if(c==d){
            cout<<"1";
            if(ax<='C'&&bx<='C'){
                cout<<"1";
                if((ax=='A'&&bx=='B')||(ax=='B'&&bx=='A')||(ax=='B'&&bx=='C')||(ax=='C'&&bx=='B')){
                    cout<<"1";
                    return 0;

                }else{
                    cout<<"0";
                    return 0;
                }
            }else{
                if(ax>'C'&&bx>'C'){
                    cout<<"11";
                    return 0;

                }
                else{
                    cout<<"00";
                    return 0;
                }
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }

    return 0;
}
