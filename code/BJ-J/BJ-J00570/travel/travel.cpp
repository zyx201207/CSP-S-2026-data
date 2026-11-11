#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool flag=true;
bool check1(char _1,char _2){
    if((_1=='A'||_1=='B'||_1=='C')&&(_2=='A'||_2=='B'||_2=='C')){
        return true;
    }
    else if((_1=='D'||_1=='F')&&(_2=='D'||_2=='F')){
        return true;
    }
    return false;
}
bool check2(char _1,char _2){
    if(_1=='D'&&_2=='F'){
        return true;
    }
    if(_1=='F'&&_2=='D'){
        return true;
    }
    if(_1=='A'&&_2=='B'){
        return true;
    }
    if(_1=='B'&&_2=='A'){
        return true;
    }
    if(_1=='B'&&_2=='C'){
        return true;
    }
    if(_1=='C'&&_2=='B'){
        return true;
    }
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0";
        flag=false;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
        cout<<1;
    }
    else{
        cout<<0;
        flag=false;
    }
    if(check1(s1[2],s2[2])&&flag){
        cout<<1;
    }
    else{
        cout<<0;
        flag=false;
    }
    if(check2(s1[2],s2[2])&&flag){
        cout<<1;
    }
    else{
        cout<<0;
        flag=false;
    }
    return 0;
}
