#include<bits/stdc++.h>
using namespace std;
string x;
string r;
string xs,rs;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>rs;
    cin>>x>>xs;

    if(x==r){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(xs[0]==rs[0]&&xs[1]==rs[1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(xs[2]<'D'&&rs[2]<'D'){
        cout<<"1";
    }
    else if(xs[2]=='D'||xs[2]=='F'&&rs[2]>='D'||rs[2]=='F'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(xs[2]-=1==rs[2]){
        cout<<"1";
    }

    else if(x[2]+=1==rs[2]){
        cout<<"1";
    }
    else if(x[2]+=2=='F'&&rs[2]=='F'){
        cout<<"1";
    }
    else if(x[2]-=2=='D'&&rs[2]=='D'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
