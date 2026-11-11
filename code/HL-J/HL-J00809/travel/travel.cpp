#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int seat1=int(s1[0])*10+int(s1[1]);
    int seat2=int(s2[0])*10+int(s2[1]);
    char cc1=s1[2];
    char cc2=s2[2];
    if(cc1>cc2){
        swap(cc1,cc2);
    }
    if(c1==c2){
        cout<<"1";
        if(seat1==seat2){
            cout<<"1";
        }
        else{
            cout<<"000";
            return 0;
        }
        if(((cc1=='A' || cc1=='B') && (cc2=='B' || cc2=='C')) || ((cc1=='D' && cc2=='F'))){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
        if((cc1=='A' && cc2=='B') || (cc1=='B' && cc2=='C')|| (cc1=='D' && cc2=='F')){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
