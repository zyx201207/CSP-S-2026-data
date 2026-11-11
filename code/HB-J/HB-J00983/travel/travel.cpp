#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a[9],b[9],c,s,p;
    char d[9];
    cin>>a[1];
    cin>>b[1];
    cin>>d[1];
    cin>>a[3];
    cin>>b[3];
    cin>>d[2];
    if(a[1]==a[3]){
        if(b[1]==b[3]){
            c=0;
        }else{
            cout<<"1000";
            }
    }else{
        cout<<"0000";
    }
    if(c==0){
        if(d[1]=='A'){
            s=0;
        }else if(d[1]=='B'){
            s=100;
        }else if(d[1]=='C'){
            s=1;
        }else if(d[1]=='D'){
            s=300;
        }else if(d[1]=='F'){
            s=300;
        }
    }
    if(c==0){
        if(d[2]=='A'){
            p=0;
        }else if(d[2]=='B'){
            p=100;
        }else if(d[2]=='C'){
            p=1;
        }else if(d[2]=='D'){
            p=300;
        }else if(d[2]=='F'){
            p=300;
        }
    }
    if(c==0){
        if(s==p){
            cout<<"1111";
        }else if(s+p==1){
            cout<<"1110";
        }else if(s+p>=300){
            cout<<"1100";
        }else {
            cout<<"1111";
        }
    }








    return 0;
}
