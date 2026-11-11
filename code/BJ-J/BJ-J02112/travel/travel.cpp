#include<bits/stdc++.h>
using namespace std;
bool check(char si1,char si2){
    int side1,side2;
    if(si1=='A'||si1=='B'||si1=='C'){
        side1=1;
    }else{
        side1=2;
    }
    if(si2=='A'||si2=='B'||si2=='C'){
        side2=1;
    }else{
        side2=2;
    }
    return side1==side2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],c2[5],s1[5],s2[5];
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1[0]==c2[0]&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1[0]==c2[0]&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1[0]==c2[0]&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])&&(s1[2]==s2[2]+1||s1[2]==s2[2]-1)){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
