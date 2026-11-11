#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,m,x,c;
    cin>>n>>m>>x>>c;
    if(n[1]==x[1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(m[1]==c[1]){
        cout<<"1";
    }

    else{
        cout<<"0";
    }
    if(m[2]=='D'&&c[2]=='F'){
        cout<<"1";
    }

    else if(m[2]=='C'&&c[2]!='D'){
        if(c[2]!='F')cout<<"1";
    }
    else if(m[2]=='A'&&c[2]!='D'){
        if(c[2]!='F')cout<<"1";
    }
    else if(m[2]=='B'&&c[2]!='D'){
        if(c[2]!='F')cout<<"1";
    }
    else{
        cout<<"0";
    }

    if(m[2]=='D'&&c[2]=='F'){
        cout<<"1";
    }

    else if(m[2]=='C'&&c[2]=='B'){
        cout<<"1";
    }
    else if(m[2]=='A'&&c[2]=='B'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }


    return 0;
}
