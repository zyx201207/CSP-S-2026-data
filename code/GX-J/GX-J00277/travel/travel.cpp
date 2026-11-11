#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,d1,d2;
    cin>>a1>>d1>>a2>>d2;
    if(a1[0]==a2[0]&&a1[1]==a2[1]){
        cout<<1;
        if(d1[0]==d2[0]&&d1[1]==d2[1]){
            cout<<1;
            if((d1[2]>='A'&&d1[2]<='C')&&(d2[2]>='A'&&d2[2]<='C')||(d1[2]=='D'||d1[2]=='F')&&(d2[2]>='D'||d2[2]<='F')){
            cout<<1;
            if(d1[0]==d2[0]){
                if(d1[1]==d2[1]&&abs(int(d1[2]-d2[2]))==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<"00";
        }
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
