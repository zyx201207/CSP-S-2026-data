#include<bits/stdc++.h>
using namespace std;
bool Q3(int c1,int c2,int n1,int n2,char char1,char char2){
    if(c1==c2&&n1==n2){
        if((char1=='A'||char1=='B'||char1=='C')&&(char2=='A'||char2=='B'||char2=='C')){
            return 1;
        }else if((char1=='D'||char2=='E')&&(char1=='D'||char2=='E')){
            return 1;
        }else{
            return 0;
        }
    }
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int n1=(s1[0]-'0')*10+(s1[1]-'0');
    int n2=(s2[0]-'0')*10+(s2[1]-'0');
    char char1=s1[2];
    char char2=s2[2];
    //Q1
    if(c1==c2)cout<<1;
    else      cout<<0;
    //Q2
    if(c1==c2){
        if(n1==n2)cout<<1;
        else      cout<<0;
    }
    else      cout<<0;
    //Q3
    if(Q3(c1,c2,n1,n2,char1,char2))cout<<1;
    else cout<<0;
    //Q4
    if(Q3(c1,c2,n1,n2,char1,char2)){
        if((char1=='A')&&(char2=='B'))cout<<1;
        else if((char1=='C')&&(char2=='B'))cout<<1;
        else if((char1=='B')&&(char2=='A'))cout<<1;
        else if((char1=='B')&&(char2=='C'))cout<<1;
        else if((char1=='D')&&(char2=='F'))cout<<1;
        else if((char1=='F')&&(char2=='D'))cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
/*
02 01A 02 01B
02 01C 02 01D 1100    if(c1==c2&&n1==n2){

    }
    else cout<<0;
    return 0;
    if(Q3(c1,c2,n1,n2,char1,char2)){
        if((char1=='A')&&(char2=='B'))cout<<1;
        else if((char1=='C')&&(char2=='B'))cout<<1;
        else if((char1=='B')&&(char2=='A'))cout<<1;
        else if((char1=='B')&&(char2=='C'))cout<<1;
        else if((char1=='D')&&(char2=='F'))cout<<1;
        else if((char1=='F')&&(char2=='D'))cout<<1;
        else cout<<0;
    }
    else cout<<0;
*/
