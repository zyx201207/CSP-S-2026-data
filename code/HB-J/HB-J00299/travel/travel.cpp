#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        cout<<"1";
        if(sr[0]==sx[0]&&sr[1]==sx[1]){
            cout<<"1";
            char r=sr[2];
            char x=sx[2];
            if((r<='C')^(x<='C')==0){
                cout<<"1";
                if(abs(int(r)-int(x))==1){
                    cout<<"1"<<endl;
                }else{
                    cout<<"0"<<endl;
                }
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }
    return 0;
}
