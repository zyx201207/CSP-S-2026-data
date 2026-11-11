#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string car1,seat1,car2,seat2,s1,s3;
    int a=0,b=0,c=0,d=0;
    char s2,s4;
    cin>>car1>>seat1>>car2>>seat2;
    if(car1==car2){
        a=1;
    }else{
        cout<<a<<b<<c<<d;
        return 0;
    }
    for(int i=0;i<=seat1.size();i++){
        if(seat1[i]>='0'&&seat1[i]<='9'){
            s1+=seat1[i];
        }else{
            s2+=seat1[i];
        }
    }
    for(int i=0;i<=seat2.size();i++){
        if(seat2[i]>='0'&&seat2[i]<='9'){
            s3+=seat2[i];
        }else{
            s4+=seat2[i];
        }
    }
    if(s1==s3){
        b=1;
    }else{
        cout<<a<<b<<c<<d;
        return 0;
    }
    if(s2=='A'&&s4=='B'||s2=='A'&&s4=='C'||s2=='B'&&s4=='A'||s2=='B'&&s4=='C'||s2=='C'&&s4=='A'||s2=='C'&&s4=='B'||s2=='D'&&s4=='F'||s2=='F'&&s4=='D'){
        c=1;
    }else{
        cout<<a<<b<<c<<d;
        return 0;
    }
    if(s2=='A'&&s4=='B'||s2=='B'&&s4=='A'||s2=='B'&&s4=='C'||s2=='C'&&s4=='B'||s2=='D'&&s4=='F'||s2=='F'&&s4=='D'){
        d=1;
    }
    cout<<a<<b<<c<<d;
}
