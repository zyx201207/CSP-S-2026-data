#include<bits/stdc++.h>
using namespace std;

int rc,xc;
char rs1,rs2,rs3,xs1,xs2,xs3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs1>>rs2>>rs3>>xc>>xs1>>xs2>>xs3;
    int rs=(rs1-48)*10+(rs2-48);
    int xs=(xs1-48)*10+(xs2-48);
    if(rc==xc){
        cout<<"1";
        if(rs==xs){
            cout<<"1";
            if(rs3<='C'&&xs3<='C'||rs3>'C'&&xs3>'C'){
                cout<<"1";
                if(abs(rs3-xs3)==1){
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
