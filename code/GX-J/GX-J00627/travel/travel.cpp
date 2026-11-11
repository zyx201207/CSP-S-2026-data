#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[2];
    char b[4];
    char c[2];
    char d[4];
    for(int i=0;i<=1;i++){
        cin>>a[i];
    }
    for(int i=0;i<3;i++){
        cin>>b[i];
    }
    for(int i=0;i<=1;i++){
        cin>>c[i];
    }
    for(int i=0;i<3;i++){
        cin>>d[i];
    }
    if(a[1]==c[1]){
    cout<<"1";
    }else{
    cout<<0<<0<<0<<0;
    return 0;
    }
    if(b[1]==d[1]){
        cout<<1;
    }else{
    cout<<0<<0<<0;
    return 0;
    }
    if(b[1]==d[1]){
       if(b[2]>='A' && b[2]<='c' && d[2]>='A' && d[2]<='c'){
            cout<<1;
        }else{
    cout<<0<<0;
    return 0;
    }
       }
       int e=d[2]-'0';
       int f=b[2]-'0';
       if(e-1==f || f-1==e){
       if(b[2]=='D' && d[2]=='C'|| d[2]=='D' && b[2]=='C'){
                cout<<0;
                return 0;

               }else{
                cout<<1;
                }
       }else
       cout<<0;

return 0;
    }


