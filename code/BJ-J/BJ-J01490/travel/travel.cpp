#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
char in[15];
string cx,sx,cr,sr;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>cx>>sx>>cr>>sr;
    if(cx==cr){
        cout<<1;
    }else{
        cout <<"0000";
        return 0;
    }
    if(sx[0]==sr[0]&&sx[1]==sr[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    char x=sx[2],r=sr[2];
    if((x>='D'&&x<='F'&&r>='D'&&r<='F')||(x>='A'&&x<='C'&&r>='A'&&r<='C')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((x==r+1||x==r-1)&&!((r=='C'&&x=='D')||(r=='D'&&x=='C'))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}