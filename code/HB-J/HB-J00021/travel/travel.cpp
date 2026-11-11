/*
CSP-J 2026

===08:31===
thank you for the whole days
4 years isnt a short time
but i have got no 1=

this might not my last csp
but im surely a grade-9 student
rp++!!!

===09:10===
t1 travel
5 all accepted, 100pts?

thanks!!!
i wont forget you!!!!
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){cout<<"0000";return 0;}
    int rr=0,rx=0;
    rr=(b[0]-'0')*10+(b[1]-'0');
    rx=(d[0]-'0')*10+(d[1]-'0');
    if(rr!=rx){cout<<"1000";return 0;}
    int rc=0,xc=0;
    switch(b[2]){
        case 'A':rc=1;break;
        case 'B':rc=2;break;
        case 'C':rc=3;break;
        case 'D':rc=8;break;
        case 'F':rc=9;break;
    }
    switch(d[2]){
        case 'A':xc=1;break;
        case 'B':xc=2;break;
        case 'C':xc=3;break;
        case 'D':xc=8;break;
        case 'F':xc=9;break;
    }
    if(abs(rc-xc)>2){cout<<"1100";return 0;}
    if(abs(rc-xc)==2){cout<<"1110";return 0;}
    cout<<"1111";
    return 0;
}