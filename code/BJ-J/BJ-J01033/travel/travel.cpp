#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }

    string p1,p2;
    p1=s1[0]+s1[1],p2=s2[0]+s2[1];
    if(p1==p2){
        cout<<1;
    }
    if(p1!=p2){
        cout<<"000";
        return 0;
    }

    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    if(s1[2]=='D'||s1[2]=='E'){
        if(s2[2]=='D'||s2[2]=='E'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }

    if(s1[2]=='A'){
        if(s2[2]=='B') cout<<1;
        else cout<<0;
    }
    if(s1[2]=='B'){
        if(s2[2]=='A'||s2[2]=='C') cout<<1;
        else cout<<0;
    }
    if(s1[2]=='C'){
        if(s2[2]=='B') cout<<1;
        else cout<<0;
    }
    if(s1[2]=='D'){
        if(s2[2]=='E') cout<<1;
        else cout<<0;
    }
    if(s1[2]=='E'){
        if(s2[2]=='D') cout<<1;
        else cout<<0;
    }
    return 0;
}
