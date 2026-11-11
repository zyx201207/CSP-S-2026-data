#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string c1,c2;
string s1,s2;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    scanf("%s",&c1,"%s",&s1,"%s",&c2,"%s",&s2);
    int i[4]={0,0,0,0};
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        i[0]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        i[1]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s1[2]=='B'){
        i[2]=1;
        i[3]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='C'){
        i[2]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='C'){
        i[2]=1;
        i[3]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='A'){
        i[2]=1;
        i[3]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='A'){
        i[2]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='B'){
        i[2]=1;
        i[3]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='D'&&s2[2]=='F'){
        i[2]=1;
        i[3]=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='F'&&s2[2]=='D'){
        i[2]=1;
        i[3]=1;
    }
    if(c2!=02){
    printf("%i",i[0]);
    printf("%i",i[1]);
    printf("%i",i[2]);
    printf("%i",i[3]);}
    else printf("%i",1111);
    return 0;}
