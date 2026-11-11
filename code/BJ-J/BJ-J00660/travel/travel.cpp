#include<bits/stdc++.h>
using namespace std;
string c,cw,x,xw;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>cw>>x>>xw;
    if(c==x){
        cout<<'1';
        if(cw[0]==xw[0]&&cw[1]==xw[1]){
            cout<<'1';
            int cl,xl;
            if(cw[2]>='A'&cw[2]<='D'){
                cl=int(cw[2]-'A'+1);
            }else cl=5;
            if(xw[2]>='A'&&xw[2]<='D'){
                xl=int(xw[2]-'A'+1);
            }else xl=5;
            int cc,xc;
            if(cl<=3){
                cc=1;
            }else cc=2;
            if(xl<=3) xc=1;
            else xc=2;
            if(cc==xc){
                cout<<'1';
                if((cl-xl==1||xl-cl==1)){
                    if((xl==3&&cl==4)||(xl==4&&cl==3)){
                        cout<<'0';
                        return 0;
                    }else cout<<'1';
                }else {
                    cout<<'0';
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}