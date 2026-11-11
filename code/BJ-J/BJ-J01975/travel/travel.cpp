#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    int ax=(c1[0]-'0')*10+c1[1]-'0',bx=(c3[0]-'0')*10+c3[1]-'0',al=(c2[0]-'0')*10+c2[1]-'0',bl=(c4[0]-'0')*10+c4[1]-'0';
    int as=c2[2]-65,bs=c4[2]-65;
    if(bs==5) bs=4;
    if(as==5) as=4;
    if(ax==bx){
        cout<<"1";
        if(al==bl){
            cout<<"1";
            if(as/3==bs/3){
                cout<<"1";
                if(abs(as-bs)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
