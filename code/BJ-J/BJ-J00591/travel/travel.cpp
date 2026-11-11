#include<bits/stdc++.h>
using namespace std;
int c1,p1,c2,p2;
char h1,h2;
bool f=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>p1>>h1>>c2>>p2>>h2;
    cout<<(c1==c2);
    if(c1!=c2){
        cout<<0<<0<<0;
        return 0;
    }
    cout<<(p1==p2);
    if(p1!=p2){
        cout<<0<<0;
        return 0;
    }
    if(h1<='C'&&h2<='C')cout<<1;
    else if(h1>='D'&&h2>='D')cout<<1;
    else {cout<<0;f=0;}
    if(!f){cout<<0;return 0;}
    if(h1<='C'&&h2<='C'){
        if(abs((int)h1-h2)==1)cout<<1;
        else cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}
