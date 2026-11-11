#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string C[2],S[2];
    for(int i=0;i<2;++i){
        cin>>C[i]>>S[i];
    }
    if(C[0]==C[1]){
        cout<<1;
        if(S[0][0]==S[1][0]&&S[0][1]==S[1][1]){
            cout<<1;
            if((S[0][2]>='A'&&S[0][2]<='C')&&(S[1][2]>='A'&&S[1][2]<='C')||(S[0][2]>='D'&&S[0][2]<='F')&&(S[1][2]>='D'&&S[1][2]<='F')){
                cout<<1;
                if(abs(S[0][2]-S[1][2])==1){
                    cout<<1;
                }else{cout<<0;}
            }else{
                cout<<00;
            }
        }else{
            cout<<000;
        }
    }else{
        cout<<0000;
    }
    return 0;
}
