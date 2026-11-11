#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int acx=0,bcx=0;
    for(int i=0;i<s1.length();i++){
        acx=acx*10+s1[i]-'0';
    }
    for(int i=0;i<s3.length();i++){
        bcx=bcx*10+s3[i]-'0';
    }
//    cout<<acx<<" "<<bcx<<endl;
//    return 0;
    if(acx==bcx){
        cout<<"1";
    }
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    int ap=0,bp=0;
    for(int i=0;i<s2.length()&&s1[i]>='0'&&s1[i]<='9';i++){
        ap=ap*10+s2[i]-'0';
    }
    for(int i=0;i<s4.length()&&s2[i]>='0'&&s2[i]<='9';i++){
        bp=bp*10+s4[i]-'0';
    }
    if(bp==ap){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    char cha=s2[2],chb=s4[2];
    if(cha>='A'&&cha<='C'&&chb>='A'&&chb<='C'||cha>='D'&&cha<='E'&&chb>='D'&&chb<='E'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(max(cha,chb)-min(cha,chb)==1||max(cha,chb)=='F'&&min(cha,chb)=='D'){
        cout<<"1";
        return 0;
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
