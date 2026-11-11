#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int pas1=0,pas2=0,pas3=0,pas4=0,seat[6]={0};
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        pas1=1;
    }
    if (s1[0]==s2[0] && s1[1]==s2[1]){
        pas2=1;
    }
    if (s1[2]=='C'||s1[2]=='A'||s1[2]=='B'){
        if (s2[2]=='C'||s2[2]=='A'||s2[2]=='B'){
            pas3=1;
        }
    }
    else{
        if (s2[2]=='D'||s2[2]=='F'){
            pas3=1;
        }
    }
    if (pas3==1){
        if (s1[2]=='A'||s2[2]=='A'){
            seat[1]=1;
        }
        if (s1[2]=='B'||s2[2]=='B'){
            seat[2]=1;
        }
        if (s1[2]=='C'||s2[2]=='C'){
            seat[3]=1;
        }
        if (s1[2]=='D'||s2[2]=='D'){
            seat[4]=1;
        }
        if (s1[2]=='F'||s2[2]=='F'){
            seat[5]=1;
        }
        for(int i=1;i<=5;i++){
            if (seat[i]==1 && seat[i+1]==seat[i]){
                pas4=1;
            }
        }
    }
    cout<<pas1<<pas2<<pas3<<pas4;
    return 0;
}
