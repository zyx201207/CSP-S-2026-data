#include<iostream>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a1,a2;
    if(s1[2]<='C')a1=0;
    else a1=1;
    if(s2[2]<='C')a2=0;
    else a2=1;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if((s1[0]==s2[0])&&(s1[1]==s2[1]))cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(a1==a2)cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1))||((s1[2]=='D')&&(s2[2]=='F'))||((s1[2]=='F')&&(s2[2]=='D')))cout<<1;
    else cout<<0;
    return 0;
}