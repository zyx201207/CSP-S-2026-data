//GZ-J0052 蒋承印 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1=0;
char s1[4];
int c2=0;
char s2[4];
cin>>c1>>s1>>c2>>s2;
int sc=0;
int sd=0;
int a[5]={0,0,0,0};
if(c1==c2){
    a[0]=1;
}
if(a[0]==1){
if(s1[0]==s2[0]&&s1[1]==s2[1]){
    a[1]=1;
}
}
else{
    cout<<'0'<<'0'<<'0'<<'0';
    return 0;
}
if(a[1]==1){
if(s1[2]=='A'&&s2[2]=='B'){a[2]=1;a[3]=1;}
if(s1[2]=='A'&&s2[2]=='C'){a[2]=1;a[3]=0;}
if(s1[2]=='A'&&s2[2]=='D'){a[2]=0;a[3]=0;}
if(s1[2]=='A'&&s2[2]=='F'){a[2]=0;a[3]=0;}
if(s1[2]=='B'&&s2[2]=='C'){a[2]=1;a[3]=1;}
if(s1[2]=='B'&&s2[2]=='D'){a[2]=0;a[3]=0;}
if(s1[2]=='B'&&s2[2]=='F'){a[2]=0;a[3]=0;}
if(s1[2]=='C'&&s2[2]=='D'){a[2]=0;a[3]=0;}
if(s1[2]=='C'&&s2[2]=='F'){a[2]=0;a[3]=0;}
if(s1[2]=='D'&&s2[2]=='F'){a[2]=1;a[3]=1;}
}
else{
    cout<<'1'<<'0'<<'0'<<'0';
    return 0;
}
if(a[0]==1){
   for(int i=0;i<4;i++){
        cout<<a[i];}
}

}
