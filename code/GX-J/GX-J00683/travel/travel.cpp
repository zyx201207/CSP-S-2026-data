#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int Rc,Xc;
    string Rz,Xz;
    cin>>Rc>>Rz>>Xc>>Xz;
    if(Rc==Xc){
        cout<<"1";
        if(Rz[1]==Xz[1]){
            cout<<"1";
            char a=Rz[2],b=Xz[2];
            if(a+b<=133 || a+b==138){
                cout<<"1";
                if(a+b==131 ||a+b==133 || a+b==138){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else cout<<"00";
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
