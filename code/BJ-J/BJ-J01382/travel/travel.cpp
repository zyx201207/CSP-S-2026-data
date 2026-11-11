#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
char a1[2],a2[3],b1[2],b2[3];bool c1,c2,c3,c4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a1>>a2>>b1>>b2;
    if(a1[0]==b1[0]&&a1[1]==b1[1]) c1=1;

    if(c1&&a2[0]==b2[0]&&a2[1]==b2[1]) c2=1;

    if(c2&&(a2[2]=='D'||a2[2]=='F')==(b2[2]=='D'||b2[2]=='F')) c3=1;

    if(c3&&abs(a2[2]-b2[2])==1||(a2[2]=='F'||b2[2]=='F'&&abs(a2[2]-b2[2])==2)) c4=1;
    cout<<c1<<c2<<c3<<c4<<endl;
    return 0;

}
