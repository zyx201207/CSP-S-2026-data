#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,a;
    string y,b;
    cin>>x>>y>>a>>b;
    if(x==a){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(y.substr(0,2)==b.substr(0,2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(y.substr(0,2)==b.substr(0,2)){
        if('A'<=y[2]&&'C'>=y[2]){
            if('A'<=b[2]&&'C'>=b[2])cout<<1;
        }
        else if('D'<=y[2]&&'E'>=y[2]){
            if('D'<=b[2]&&'E'>=b[2])cout<<1;
        }
        else{
            cout<<0;
        }
    }
    if(y.substr(0,2)==b.substr(0,2)){
        if(abs(y[2]-b[2])==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
}
