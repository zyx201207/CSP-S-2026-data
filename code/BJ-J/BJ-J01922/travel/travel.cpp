#include<bits/stdc++.h>
using namespace std;
int sitr;
int sitx;
char lstr[16];
char lstx[16];
char empty;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sitr;
    cin>>lstr[1];
    cin>>lstr[2];
    cin>>lstr[3];
    cin>>sitx;
    cin>>lstx[1];
    cin>>lstx[2];
    cin>>lstx[3];
    if(sitr!=sitx){
        cout<<"0000";
    }else{
        cout<<1;
        if(lstr[1]*10+lstr[2]!=lstx[1]*10+lstx[2]){
            cout<<"000";
        }else{
            cout<<1;
            if((!(lstr[3]-'A'+lstx[3]-'A'>7))&&((lstr[3]-'A')>2||(lstx[3]-'A')>2)){
                cout<<"00";
            }else{
                cout<<1;
                if((lstr[3]-'A')-(lstx[3]-'A')>1||(lstx[3]-'A')-(lstr[3]-'A')>1){
                    cout<<"0";
                }else{
                    cout<<1;
                }
            }
        }
    }
    return 0;
}
