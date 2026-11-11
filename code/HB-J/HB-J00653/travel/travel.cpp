#include<bits/stdc++.h>
using namespace std;

char b[3];
char d[3];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a;
    cin>>a;

    for(int i=1;i<=3;i++){
        cin>>b[i];
    }
    char c;
    cin>>c;

    for(int i=1;i<=3;i++){
        cin>>d[i];
    }

    if(a==c){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    
    if(b[1]==d[1]&&b[2]==d[2]){
         cout<<"1";
    }
    else{
        cout<<"0";
    }

    if(b[3]=='A'&&d[3]=='B'){
          cout<<"1"<<"1";
    }
    else if(b[3]=='A'&&d[3]=='C'){
         cout<<"1";
    }
    else if(b[3]=='B'&&d[3]=='C'){
         cout<<"1"<<"1";
    }
    else if(d[3]=='A'&&b[3]=='B'){
          cout<<"1"<<"1";
    }
    else if(d[3]=='A'&&b[3]=='C'){
         cout<<"1";
    }
    else if(d[3]=='B'&&b[3]=='C'){
         cout<<"1"<<"1";
    }
    else{
        cout<<"0"<<"0";
    }
    
    if(b[3]=='D'&&d[3]=='F'){
         cout<<"1"<<"1";
    }
    else if(b[3]=='F'&&d[3]=='D'){
         cout<<"1"<<"1";
    }
    else if(d[3]=='D'&&b[3]=='F'){
         cout<<"1"<<"1";
    }
    else if(d[3]=='F'&&b[3]=='D'){
         cout<<"1"<<"1";
    }
    else {
        cout<<"0"<<"0";
    }

    return 0;
}