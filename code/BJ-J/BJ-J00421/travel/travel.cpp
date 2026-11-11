#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
        if(b1[0]==b2[0]&&b1[1]==b2[1]){
            if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')||(b1[2]=='D'||b1[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
                if(abs(b1[2]-b2[2])==1){
                    cout<<"1111";
                }else{

                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
