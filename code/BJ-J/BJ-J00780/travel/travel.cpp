#include <bits/stdc++.h>
using  namespace std;
int c1,c2;
int s1_,s2_,x;
int a,b,c;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin );
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<"1";
        a=1;
    }else{
        cout<<"0000";
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
        b=1;
    }else{
        cout<<"000";
        return 0;
    }

    if(s1[2]=="A"||s1[2]=="B"||s1[2]=="C"){
        s1_=1;
    }
    if(s2[2]=="A"||s2[2]=="B"||s2[2]=="C"){
        s2_=1;
    }
    if(s1_==s2_){
        cout<<"1";
        c=1;
    }else{
        cout<<"00";
        return 0;
    }

    if((s1[2]=="F"&&s2[2]=="D")||(s1[2]=="D"&&s2[2]=="F")){
        x=1;
    }
    if((s1[2]=="A"&&s2[2]=="B")||(s1[2]=="B"&&s2[2]=="A")||(s1[2]=="C"&&s2[2]=="B")||(s1[2]=="B"&&s2[2]=="C")){
        x=1;
    }
    if(a==1&&b==1&&c==1&&x=1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}