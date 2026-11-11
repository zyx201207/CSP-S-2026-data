#include<bits/stdc++.h>
using namespace std;
bool f3(char x,char y){
    if('A'<=x&&x<='C'&&'A'<=y&&y<='C')return true;
    if((x=='D'||x=='F')&&(y=='D'||y=='F'))return true;
    return false;
}
bool f4(char x,char y){
    if(x>y)swap(x,y);
    if(x=='A'&&y=='B')return true;
    if(x=='B'&&y=='C')return true;
    if(x=='D'&&y=='F')return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //Question1
    if(c1==c2)printf("1");
    else {printf("0000");return 0;}
    //Question2
    if(s1[0]==s2[0]&&s1[1]==s2[1])printf("1");
    else {printf("000");return 0;}
    //Question3
    if(f3(s1[2],s2[2]))printf("1");
    else {printf("00");return 0;}
    //Question4
    if(f4(s1[2],s2[2]))printf("1");
    else printf("0");
    return 0;
}
