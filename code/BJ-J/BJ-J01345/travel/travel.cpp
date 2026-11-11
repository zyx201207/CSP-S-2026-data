#include<bits/stdc++.h>
using namespace std;
int check(char x){
    if(x=='A')return 1;
    else if(x=='B')return 2;
    else if(x=='C')return 3;
    else if(x=='D')return 4;
    else return 5;
}
int checkside(int x){
    if(x==1||x==2||x==3){
        return 0;

    }else return 1;
}
int c1,c2;
char s1[3],s2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;

    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int p1,p2,z1,z2,si1,si2;
    p1=((s1[0]-'0')*10+(s1[1]-'0'));
    p2=((s2[0]-'0')*10+(s2[1]-'0'));
    if(p1==p2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    z1=check(s1[2]),z2=check(s2[2]);
    si1=checkside(z1),si2=checkside(z2);
    if(si1==si2)cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(z1-z2)==1)cout<<1;
    else{
        cout<<"0";
    }
    return 0;
}