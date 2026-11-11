#include<iostream>
#include<cstring>
using namespace std£»

int main{
        //freopen("travel.in","r",stdin);
        //freopen("travel.out","w",stdout);
        char s1[][]=0,s2[][]=0;
        int a=0,b=0,c=0,d=0;

        for(int a=0;a<3;a++){
        for(int b=0;b>3;b++){
        cin>>s1[a][b];
        }}

        for(c=0;c<3;c++){
        for(d=0;d>3;d++){
        cin>>s2[c][d];
        }}
        if(c1==c2){
        cout<<'1'<<' ';}
        else{
        cout<<"0 0 0 0";
        return 0;
        }
        if((c1==c2)&&(s1[a][]==s2[c][])){
        cout<<'1'<<' ';}
        else{
        cout<<"1 0 0 0";
        return 0;
        }
        if((c1==c2)&&(s1[a][]==s2[c][])&&((('A'<=s1[][b]>='C')&&('A'<=s2[][d]>='C'))||(('D'<=s1[][b]>='F')&&('D'<=s2[][d]>='F'))){
        cout<<'1'<<' ';}
        else{
        cout<<"1 1 0 0";
        return 0;}

        if((c1==c2)&&(s1[a][]==s2[c][])&&((('A'<=s1[][b]>='C')&&('A'<=s2[][d]>='C'))||(('D'<=s1[][b]>='F')&&('D'<=s2[][d]>='F')))&&((s1[][b+1]==s2[][d])||(s1[][b-1]==s2[][d]))){
        cout<<'1'<<' ';}
        else{
        cout<<"1 1 1 0";
        return 0;}
        return 0;}
