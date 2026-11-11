#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    string a,b,c,d,w,e,r,x,y;
    cin>>a>>c>>b>>d;
    int char q;
    for(int i=0;i<3;i++){
        q=c[i];
        if(q>='A'&&q<='F'){
            w=q;
        }
        if(q>=1&&q<=18){
            x+=q;
        }
    for(int j=0;j<3;j++){
        e=d[i];
        if(e>='A'&&e<='F'){
            r=e;
        }
        if(e>=1&&e<=18){
            y+=e;
        }
    }
    if(a==b){
        cout<<"1";
    }
    else(){
        cout<<"0";
    }
    if(x==y){
        cout<<"1";
    }
    else(){
        cout<<"0";
    }
    if(w+r=='D+F'||w+r=='A+B'||w+r=='A+C'||w+r=='B+C'){
        cout<<"1";
    }
    else(){
        cout<<"0";
    }
    if(w+r=='D+F'||w+r=='A+B'||w+r=='A+C'){
        cout<<"1";
    }
    else(){
        cout<<"0";
    }
    
    return 0;
}
