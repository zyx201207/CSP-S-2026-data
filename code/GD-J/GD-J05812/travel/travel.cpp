#include<iostream>
using namespace std;

bool f(char a,char b){
    if(a==b)return false;
    if(a-1==b)return true;
    if(b-1==a)return true;
    if(a=='D'&&b=='F')return true;
    if(b=='D'&&a=='F')return true;
    return false;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2;char a3,b3;cin>>a1>>a2>>a3>>b1>>b2>>b3;
    bool t1,t2,t3,t4;
    t1=a1==b1;t2=t1&&a2==b2;t3=t2&&(a3<'D')==(b3<'D');t4=t3&&f(a3,b3);
    cout<<t1<<t2<<t3<<t4;
    return 0;
}
