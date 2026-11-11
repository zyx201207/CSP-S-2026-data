#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a;
    int s;
    int k=0;
    string z,x;
    cin>>a>>z>>s>>x;
    if(a!=s){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(z[0]!=x[0]){
        if(z[1]!=x[1]){
            cout<<1000;
            return 0;
        }
    }else{
        cout<<11;
    }
    if((z[2]=='A'||z[2]=='B'||z[2]=='C')&&(x[2]=='A'||x[2]=='B'||x[2]=='C')){
        cout<<1;
        k=k+1;
    }
    if((z[2]=='F|'|z[2]=='D')&&(x[2]=='F'||x[2]=='D')){
        cout<<11;
        return 0;
    }
    if(k==0){
        cout<<00;
        return 0;
    }
    if(k==1){
        k=0;
        if(z[2]=='A'&&x[2]=='B'){
            cout<<1;
            return 0;
        }
        if(z[2]=='B'&&x[2]=='A'){
            cout<<1;
            return 0;
        }
        if(z[2]=='B'&&x[2]=='C'){
            cout<<1;
            return 0;
        }
        if(z[2]=='C'&&x[2]=='B'){
            cout<<1;
            return 0;
        }
    }
    if(k==0){
        cout<<0;
    }
    return 0;
}
