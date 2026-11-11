#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
char c1[5],c2[5],s1[5],s2[5];
ll Rc,Rs,Xc,Xs,Rw,Xw;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    Rc=10*c1[0]+c1[1];
    Rs=10*s1[0]+s1[1];
    Xc=10*c2[0]+c2[1];
    Xs=10*s2[0]+s2[1];
    Rw=s1[2]-'A'+1;
    Xw=s2[2]-'A'+1;
    if(Rc==Xc) cout<<1;
    else cout<<"0";
    if(Rc==Xc&&Rs==Xs){
        cout<<"1";
        if((Rw>=1&&Rw<=3&&Xw>=1&&Xw<=3)){
            cout<<"1";
            if(abs(Rw-Xw)==1) cout<<"1";
            else cout<<"0";
        }
        else if(Rw>=4&&Rw<=6&&Xw>=4&&Xw<=6){
            cout<<"11";
        }
        else{
            cout<<"00";
        }
    }
    else{
        cout<<"000";
    }
    return 0;
}