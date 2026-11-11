#include<bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cc1>>cc2>>ss1>>ss2;
    if(cc2[2]=='F'){
        cc2[2]='E';
    }
    if(ss2[2]=='F'){
        ss2[2]='E';
    }
    if(cc1!=ss1){
        cout<<"0000";
    }else{
        cout<<"1";
        if(cc2[0]!=ss2[0]||cc2[1]!=ss2[1]){
            cout<<"000";
        }else{
            cout<<"1";
            if(cc2[2]-'A'<=2&&ss2[2]-'A'<=2||cc2[2]-'A'>=3&&ss2[2]-'A'>=3){
                cout<<"1";
                if(abs((int)(cc2[2]-'A')-(int)(ss2[2]-'A'))==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }


    }

    return 0;
}
