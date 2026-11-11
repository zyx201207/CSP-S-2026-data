#include<iostream>
using namespace std;
typedef long long ll;
int r1,x1;
char r2[10],x2[10];
bool f(char a,char b){
    if(a=='F'&&b=='D')return true;
    if(a=='D'&&b=='F')return true;
    if(a=='F'||b=='F'||a=='D'||b=='D')return false;
    return true;
}
bool f2(char a,char b){
    if(a=='F'&&b=='D')return true;
    if(a=='D'&&b=='F')return true;
    if(a=='A'&&b=='B')return true;
    if(a=='B'&&b=='C')return true;
    if(a=='B'&&b=='A')return true;
    if(a=='C'&&b=='B')return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(r2[0]==x2[0]&&r2[1]==x2[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(f(r2[0],x2[0])&&f(r2[1],x2[1])){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(f2(r2[2],x2[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
