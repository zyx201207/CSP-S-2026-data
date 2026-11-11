#include<iostream>
using namespace std;
string r1,r2,x1,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        cout<<1;
        if(r2[0]==x2[0]&&r2[1]==x2[1]){
            cout<<1;
            if((r2[2]<='C'&&x2[2]<='C')||(r2[2]>='D'&&x2[2]>='D')){
                cout<<1;
                if((r2[2]=='C'&&x2[2]=='A')||(r2[2]=='A'&&x2[2]=='C')){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
}
