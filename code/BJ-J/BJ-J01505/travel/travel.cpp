#include<bits/stdc++.h>
using namespace std;
int s[5];
string rc,rz,xc,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc){
        s[0]=1;
    }
    int rm=0,xm=0;
    if(rz[2]=='A'||rz[2]=='B'||rz[2]=='C'){
        rm=1;
    }
    else{
        rm=0;
    }
    if(xz[2]=='A'||xz[2]=='B'||xz[2]=='C'){
        xm=1;
    }
    else{
        xm=0;
    }
    int r=((rz[0]-'0')%10)*10+(rz[1]-'0')%10;//r=((rz[0]-'0')%10)*10+(rz[1]-'0')%10
    int x=((xz[0]-'0')%10)*10+(xz[1]-'0')%10;
    //cout<<xz[0]-'0'<<" "<<xz[1]-'0'<<endl;
    //cout<<r<<" "<<x;
    if(r==x&&s[0]==1){
        s[1]=1;
    }
    if(s[1]==1&&rm==xm){
        s[2]=1;
    }
    if((s[2]==1&&rz[2]+1==xz[2])||(s[2]==1&&rz[2]-1==xz[2])){
        s[3]=1;
    }
    for(int i=0;i<=3;i++){
        cout<<s[i];
    }
    return 0;
}
