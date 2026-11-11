#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    string p1,p2;
    char s1,s2;
    p1.push_back(a2[0]);
    p1.push_back(a2[1]);
    p2.push_back(b2[0]);
    p2.push_back(b2[1]);
    s1=a2[2];
    s2=b2[2];
    if(a1==b1){
        cout<<1;
    }else{
        cout<<0;
    }
    if(p1==p2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1>='A'&&s1<='C'&&s2>='A'&&s2<='C'||s1>='D'&&s1<='F'&&s2>='D'&&s2<='F'){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1+1==s2||s1-1==s2){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
