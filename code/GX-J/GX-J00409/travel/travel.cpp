#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int tx,tp,tc;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        tx=1;
        cout<<1;
    }
    else{
        tx=0;
        cout<<"0000";
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        tp=1;
        cout<<1;}
    else{
        tp=0;
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            if(tx==1&&tp==1){
                tc=1;
                cout<<"1";
            }
        }
    }
    if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
        tc=1;
        cout<<"1";}
    if(tc!=1){
        tc=0;
        cout<<"00";
        return 0;}

    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'){
        if(tx==1&&tp==1&&tc==1){
            cout<<"1";
        }
    }
    if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'){
        if(tx==1&&tp==1&&tc==1){
            cout<<"1";
            return 0;
        }
    }
    cout<<"0";





    return 0;
}
