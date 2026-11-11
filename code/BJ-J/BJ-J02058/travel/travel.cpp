#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
        if(c2[0]==c4[0]&&c2[1]==c4[1]){
            cout<<"1";
            s1=c2[2]-'A'+1;
            s2=c4[2]-'A'+1;
            if(s1<=3&&s2<=3||s1>3&&s2>3){
                cout<<"1";
                if(max(s1,s2)-min(s1,s2)==1){
                    cout<<"1";
                }else{
                    cout<<"0";
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
    return 0;
}