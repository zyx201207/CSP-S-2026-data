#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int e[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin>>a>>c>>b>>d;
    if(a==b) e[0]=1;
    else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==d[0]){
        if(c[1]==d[1]){
            e[1]=1;
        }
        else{
            cout<<"1000";
            return 0;
        }
    }

    else{
        cout<<"1000";
        return 0;
    }
    if(c[2]=='A'||c[2]=='C'||c[2]=='B'){
        if(d[2]=='A'||d[2]=='C'||d[2]=='B')
            e[2]=1;
    }
    else if(d[2]=='F'||d[2]=='D') e[2]=1;
    else{
        cout<<"1100";
        return 0;
    }
    if(c[2]=='A'){
        if(d[2]=='B')e[3]=1;
    }
    if(c[2]=='B'){
        if(d[2]=='A')e[3]=1;
    }
    if(c[2]=='C'){
        if(d[2]=='B')e[3]=1;
    }
    if(c[2]=='B'){
        if(d[2]=='C')e[3]=1;
    }
    if(c[2]=='D'){
        if(d[2]=='F')e[3]=1;
    }
    if(c[2]=='F'){
        if(d[2]=='D')e[3]=1;
    }
    for(int i=0;i<4;i++){
        cout<<e[i];
    }
    return 0;
}
