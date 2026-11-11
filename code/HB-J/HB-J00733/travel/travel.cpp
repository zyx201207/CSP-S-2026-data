#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rs,xc,xs;
    string a="";
    string s1="1",s0="0";
    int b=1;
    cin>>rc>>rs>>xc>>xs;


    if(rc==xc){
        a+=s1;
    }else{
        a+=s0;
        b=0;
        }

    if(b==1){
        if(rs[0]==xs[0]&&rs[1]==xs[1]){
            a+=s1;
        }else{
            a+=s0;
            b=0;}
    }else{
            a+=s0;}



    char r,x;
      r=rs[2];
      x=xs[2];

    if(b==1){
        if(r<='C'&&x<='C'){
            a+=s1;
        }else if(r>'C'&&x>'C'){
            a+=s1;}
        else{
            a+=s0;
            b=0;}
    }else{
            a+=s0;}

    if(b==1){
        if((r+1==x||r-1==x)&&(r<'C'&&x<='C')){
            a+=s1;
        }else if((r+2==x||r-2==x)&&(r>'C'&&x>'C')){
            a+=s1;}
        else{
            a+=s0;
            b=0;}
    }else{
            a+=s0;}


    cout<<a;
    return 0;
}
