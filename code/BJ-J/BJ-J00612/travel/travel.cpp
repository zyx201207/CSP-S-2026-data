#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a1,a2,a3,a4,a5;
    int anx,any;
    cin>>a1>>a2>>a3>>a4>>a5;
    if(a1=='0'){
        anx=a2-'0';
    }else{
        anx=(a1-'0')*10+a2-'0';
    }
    if(a3=='0'){
        any=a4-'0';
    }else{
        any=(a3-'0')*10+a4-'0';
    }
    char b1,b2,b3,b4,b5;
    int bnx,bny;
    cin>>b1>>b2>>b3>>b4>>b5;
    if(b1=='0'){
        bnx=b2-'0';
    }else{
        bnx=(b1-'0')*10+b2-'0';
    }
    if(b3=='0'){
        bny=b4-'0';
    }else{
        bny=(b3-'0')*10+b4-'0';
    }
    bool w=1;
    if(anx==bnx){
        cout<<1;
    }else{
        cout<<0;
        w=0;
    }
    if(any==bny&&w==1){
        cout<<1;
    }else{
        cout<<0;
        w=0;
    }
    if(a5=='D'&&b5=='E'||a5=='E'&&b5=='D'||a5=='A'&&b5=='B'||a5=='B'&&b5=='A'||a5=='A'&&b5=='C'||a5=='C'&&b5=='A'||a5=='B'&&b5=='C'||a5=='C'&&b5=='B'){
        if(w==1){
            cout<<1;
        }else{
            cout<<0;
            w=0;
        }
    }else{
        cout<<0;
        w=0;
    }
    if(a5=='A'&&b5=='B'||a5=='B'&&b5=='A'||a5=='B'&&b5=='C'||a5=='C'&&b5=='B'||a5=='D'&&b5=='E'||a5=='E'&&b5=='D'){
        if(w==1){
            cout<<1;
        }else{
            cout<<0;
            w=0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
