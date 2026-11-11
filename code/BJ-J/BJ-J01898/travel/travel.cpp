#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
void check(){
    if(s1!=s3){
        cout<<"0000";
        return;
    }
    cout<<1;
    if(s2[0]!=s4[0]||s2[1]!=s4[1]){
        cout<<"000";
        return;
    }
    cout<<1;
    char c1=s2[2],c2=s4[2];
    if(c1>c2)swap(c1,c2);
    if(c2=='F'){
        if(c1=='D')cout<<"11";
        else cout<<"00";
        return;
    }if(c2=='D'){
        cout<<"00";
        return;
    }if(c2=='C'){
        if(c1=='B')cout<<"11";
        else cout<<"10";
        return;
    }if(c2=='B'){
        cout<<"11";
        return;
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    check();
    return 0;
}
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
