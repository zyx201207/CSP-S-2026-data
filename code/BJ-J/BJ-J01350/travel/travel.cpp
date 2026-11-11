#include<bits/stdc++.h>
using namespace std;
string c1,s11,c2,s21;
char s12,s22;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s12;
    s11=s12;
    cin>>s12;
    s11=s11+s12;
    cin>>s12;
    cin>>c2;
    cin>>s22;
    s21=s22;
    cin>>s22;
    s21=s21+s22;
    cin>>s22;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s11==s21){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(((s12=='A'||s12=='B'||s12=='C')&&(s22=='A'||s22=='B'||s22=='C'))||((s12=='D'||s12=='F')&&(s22=='D'||s22=='F'))){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s12=='A'&&s22=='B'){
        cout<<1;
    }
    else if(s12=='B'&&s22=='A'){
        cout<<1;
    }
    else if(s12=='B'&&s22=='C'){
        cout<<1;
    }
    else if(s12=='C'&&s22=='B'){
        cout<<1;
    }
    else if(s12=='D'&&s22=='F'){
        cout<<1;
    }
    else if(s12=='F'&&s22=='D'){
        cout<<1;
    }
    else{
        cout<<0;
    }
return 0;
}
