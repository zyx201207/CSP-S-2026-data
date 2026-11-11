#include <bits/stdc++.h>
using namespace std;
void open();
char s[5][3];
string ton="ABCDEF";
int main(){
    open();
    for(int i=0;i<2;i++){
        cin>>s[0][i];
    }
    for(int i=0;i<3;i++){
        cin>>s[1][i];
    }
    for(int i=0;i<2;i++){
        cin>>s[2][i];
    }
    for(int i=0;i<3;i++){
        cin>>s[3][i];
    }
    if(s[0][0]==s[2][0] && s[0][1]==s[2][1]) {
        cout<<1;
         if(s[1][0]==s[3][0] && s[1][1]==s[3][1]) {
            cout<<1;
            if((ton.find(s[1][2])<=3 && ton.find(s[3][2])<=3) || (ton.find(s[1][2])>3 && ton.find(s[3][2])>3)){
                cout<<1;
                if(max(ton.find(s[1][2]),ton.find(s[3][2]))-1==min(ton.find(s[1][2]),ton.find(s[3][2]))){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
void open(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
