#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,w,x,y,z;
char i,j;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>i>>c>>d>>j;
    if(a==c){
        w=1;
    }
    if(w==1){
        if(b==d){
            x=1;
        }
    }
    if(x==1){
        if(i=='A'&&(j=='B'||j=='C')){
            y=1;
        }
        if(i=='B'&&(j=='A'||j=='C')){
            y=1;
        }
        if(i=='C'&&(j=='A'||j=='B')){
            y=1;
        }
        if(i=='D'&&j=='F'){
            y=1;
        }
        if(i=='F'&&j=='D'){
            y=1;
        }
    }
    if(y==1){
        if(i=='A'&&j=='B'){
            z=1;
        }
        if(i=='B'&&(j=='A'||j=='C')){
            z=1;
        }
        if(i=='C'&&j=='B'){
            z=1;
        }
        if(i=='D'&&j=='F'){
            z=1;
        }
        if(i=='F'&&j=='D'){
            z=1;
        }
    }
    cout<<w<<x<<y<<z;
    return 0;
}
