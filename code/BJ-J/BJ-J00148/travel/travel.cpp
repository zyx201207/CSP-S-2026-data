#include<iostream>
#include<cstdio>
using namespace std;
string rp,xp,rn,xn;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rp>>rn>>xp>>xn;
    if(rp!=xp){
        cout<<0<<0<<0<<0;
        return 0;
    }
    f1=1;
    if(rn[0]==xn[0]&&rn[1]==xn[1]){
        f2=1;
        if(rn[2]<='C'&&xn[2]<='C'){
            f3=1;
            if(rn[2]!='B'&&xn[2]!='B')f4=0;
            else f4=1;
        }
        if(rn[2]>='D'&&xn[2]<='D')f3=1,f4==1;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
