#include<bits/stdc++.h>
using namespace std;
string s1,ss1,s2,ss2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>ss1>>s2>>ss2;
    if(s1!=s2){
        cout<<"0000";
    }else{
        cout<<'1';
        if((ss1[0]==ss2[0]&&ss1[1]!=ss2[1])||(ss1[0]!=ss2[0]&&ss2[1]!=ss1[1])||(ss1[0]!=ss2[0]&&ss2[1]==ss1[1])){
                cout<<"000";
        }else{
           cout<<'1';
           char b1=ss1[2],b2=ss2[2];
           if(((b1=='F'&&(b2>='A'&&b2<='C'))||(b1=='D'&&(b2>='A'&&b2<='C')))||((b2=='F'&&(b1>='A'&&b1<='C'))||(b2=='D'&&(b1>='A'&&b1<='C')))){
            cout<<"00";
           }else{
           cout<<'1';
           if((b1=='F'&&b2=='D')||(b1=='D'&&b2=='F')){
            cout<<'1';
           }else if(b1=='A'&&b2=='B'){
           cout<<'1';
           }else if(b1=='B'&&(b2=='A'||b2=='C')){
           cout<<'1';
           }else if(b1=='C'&&b2=='B'){
           cout<<'1';
           }else{
           cout<<'0';
           }
           }
        }
    }
    return 0;
}
