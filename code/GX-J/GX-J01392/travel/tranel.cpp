#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int lsl[5]={A,B,C,D,F}
    int ls[5]={A,B,C,D,F}
    int psl[18]={01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18}
    int ps[18]={01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18}
    if(c1==s1){
        cout<<'1';
        if(ps1==ps2)
            cout<<'1';
        else
            cout<<'0';
        if((lsl=='D'&&ls=='E')||(lsl=='A'&&ls=='B')||(lsl=='B'&&ls=='C')||(lsl=='B'&&ls=='C'))
                cout<<'1';
            else
                cout<<'1';
        if((lsl=='A'&&ls=='B')||(lsl=='B'&&ls=='C')||(lsl=='D'&&ls=='F'))
            cout<<'1';
        else cout<<'0'<<endl;
    }else
        cout<<"0000";
    return 0;
}
