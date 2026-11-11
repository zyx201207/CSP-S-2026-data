#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    string p=s1.substr(0,1);
    string p2=s2.substr(0,1);
    if(p==p2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char c=s1[2];
    char e=s2[2];
    if((c=='A'&&e=='B')||(c=='B'&&e=='A')||(c=='B'&&e=='C')||(c=='C'&&e=='B')||(c=='A'&&e=='C')||(c=='C'&&e=='A')||(c=='D'&&e=='F')||(c=='F'&&e=='D')){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(abs(c-e)==1&&!((c=='C'&&e=='D')||(c=='D'&&e=='C'))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
