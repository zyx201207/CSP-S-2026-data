#include<bits/stdc++.h>
using namespace std;
string a3,b3,a4,b4;
int a1,a2,b1,b2,a0,b0;
int zh(char s){
    if(s=='A')return 1;
    if(s=='B')return 2;
    if(s=='C')return 3;
    if(s=='D')return 5;
    if(s=='F')return 6;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a3>>a4>>b3>>b4;
    a1=(a3[0]-'0')*10+(a3[1]-'0');
    b1=(b3[0]-'0')*10+(b3[1]-'0');
    a2=(a4[0]-'0')*10+(a4[1]-'0');
    b2=(b4[0]-'0')*10+(b4[1]-'0');
    char l=a4[2],r=b4[2];
    int a0=zh(l),b0=zh(r);
    //cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<" "<<a0<<" "<<b0<<endl;
    if(a1!=b1){
        cout<<"0000"<<endl;
    }
    else if(a2!=b2){
        cout<<"1000"<<endl;
    }
    else if((a0>4&&b0<4)||(a0<4&&b0>4)){
        cout<<"1100"<<endl;
    }
    else if(abs(a0-b0)>1){
        cout<<"1110"<<endl;
    }
    else{
        cout<<"1111"<<endl;
    }
    return 0;
}
