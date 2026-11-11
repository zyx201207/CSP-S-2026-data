#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,j,b2,d2;
int main(){
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(b-d<=5&&b-d>=-5){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    cout<<1;
    if(b-d<=1&&b-d>=-1){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
