#include<bits/stdc++.h>
using namespace std;
char a[3];
char b[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int xiang1;
    cin>>xiang1;
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int xiang2;
    cin>>xiang2;
    for(int i=0;i<3;i++){
        cin>>b[i];
    }
    if(xiang1==xiang2){
        cout<<"1";
    }else{
        cout<<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<"1";
    }else{
        cout<<"0"<<"0"<<"0";
        return 0;
    }
    if(a[2]=='A'&&b[2]=='B'){
        cout<<"1";
    }else if(a[2]=='A'&&b[2]=='C'){
        cout<<"1";
    }else if(a[2]=='B'&&b[2]=='A'){
        cout<<"1";
    }else if(a[2]=='B'&&b[2]=='C'){
        cout<<"1";
    }else if(a[2]=='C'&&b[2]=='A'){
        cout<<"1";
    }else if(a[2]=='C'&&b[2]=='B'){
        cout<<"1";
    }else if(a[2]=='D'&&b[2]=='F'){
        cout<<"1";
    }else if(a[2]=='F'&&b[2]=='D'){
        cout<<"1";
    }else{
        cout<<"0"<<"0";
        return 0;
    }
    if(a[2]=='A'&&b[2]=='B'){
        cout<<"1";
    }else if(a[2]=='B'&&b[2]=='C'){
        cout<<"1";
    }else if(a[2]=='D'&&b[2]=='F'){
        cout<<"1";
    }else if(a[2]=='F'&&b[2]=='D'){
        cout<<"1";
    }else{
        cout<<"0";
    }
return 0;
}
