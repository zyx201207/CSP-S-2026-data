#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char ch1,ch2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1!=s2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(ch1<='C'&&ch2>='D'||ch1>='D'&&ch2<='C'){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(ch1=='A'&&ch2=='B'||ch1=='B'&&ch2=='C'||ch1=='D'&&ch2=='F'){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
