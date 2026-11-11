#include<iostream>
#include<cmath>
using namespace std;
string a,b,c,d;
int e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    e=b[1]+b[0]*10;
    f=d[1]+d[0]*10;
    if(a==c){
        cout<<"1";
        if(e==f){
            cout<<"1";
            if((b[2]>'C'&&d[2]>'C')||(b[2]<='C'&&d[2]<='C')){
                cout<<"1";
                if(abs(b[2]-d[2])==1) cout<<"1";
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
