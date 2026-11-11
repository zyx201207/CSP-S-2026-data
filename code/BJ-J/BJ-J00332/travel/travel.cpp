#include<bits/stdc++.h>
using namespace std;
bool q=1,w=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    for(int i=1;i<=2;i++){
        cin>>a[i];
    }
    for(int i=1;i<=3;i++){
        cin>>b[i];
    }
    for(int i=1;i<=2;i++){
        cin>>c[i];
    }
    for(int i=1;i<=3;i++){
        cin>>d[i];
    }


    for(int i=1;i<=2;i++){
        if(a[i]!=c[i]){
            q=0;
        }
    }
    if(q){
        cout<<1;
    }
    if(!q){
        cout<<0<<0<<0<<0;
        return 0;
    }


    for(int i=1;i<=2;i++){
        if(b[i]!=d[i]){
            w=0;
        }
    }
    if(q && w){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }

    if(b[3]=='A'){
            if(d[3]=='B'){
                cout<<1<<1;
            }
            if(d[3]=='C'){
                cout<<1<<0;
            }
            if(d[3]=='D' || d[3]=='F'){
                cout<<0<<0;
            }
    }
    if(b[3]=='B'){
            if(d[3]=='A'){
                cout<<1<<1;
            }
            if(d[3]=='C'){
                cout<<1<<1;
            }
            if(d[3]=='D' || d[3]=='F'){
                cout<<0<<0;
            }
    }
    if(b[3]=='C'){
            if(d[3]=='A'){
                cout<<1<<0;
            }
            if(d[3]=='B'){
                cout<<1<<1;
            }
            if(d[3]=='D' || d[3]=='F'){
                cout<<0<<0;
            }
    }
    if(b[3]=='D'){
            if(d[3]=='F'){
                cout<<1<<1;
            }
            if(d[3]=='A' || d[3]=='B' || d[3]=='C'){
                cout<<0<<0;
            }
    }
    if(b[3]=='F'){
            if(d[3]=='D'){
                cout<<1<<1;
            }
            if(d[3]=='A' || d[3]=='B' || d[3]=='C'){
                cout<<0<<0;
            }
    }
    return 0;

}