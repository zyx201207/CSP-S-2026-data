#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string c4,c6;
int c3,c5;
bool flag,r,x;
int r1,x1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    c3+=s1[0]-'0',c3+=s1[1]-'0';
    c4=s1[2];
    c5+=s2[0]-'0',c5+=s2[1]-'0';
    c6=s2[2];
    if(c4=="A"||c4=="B"||c4=="C"){
        r=0;
    }else if(c4=="D"||c4=="E"){
        r=1;
    }
    if(c6=="A"||c6=="B"||c6=="C"){
        x=0;
    }else if(c6=="D"||c6=="E"){
        x=1;
    }
    if(c4=="A"){
        r1=1;
    }
    if(c4=="B"){
        r1=2;
    }
    if(c4=="C"){
        r1=3;
    }
    if(c4=="D"){
        r1=4;
    }
    if(c4=="E"){
        r1=5;
    }
    if(c6=="A"){
        x1=1;
    }
    if(c6=="B"){
        x1=2;
    }
    if(c6=="C"){
        x1=3;
    }
    if(c6=="D"){
        x1=4;
    }
    if(c6=="E"){
        x1=5;
    }
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c3==c5&&c1==c2){
        cout<<1;
        flag=1;
    }else{
        cout<<0;
    }
    if(flag==1&&((r==0&&x==0)||(r==1&&x==1))&&c3==c5&&c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(flag==1&&((r==0&&x==0)||(r==1&&x==1))&&r1+1==x1||r1-1==x1&&c3==c5&&c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
