#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    string a,b,c,d;
    int x=0,y=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0] and b[1]==d[1]){
            cout<<1;
            if(b[2]=='A' or b[2]=='B' or b[2]=='C'){
                x=1;
            }if(d[2]=='A' or d[2]=='B' or d[2]=='C'){
                y=1;
            }if(x==y){
                cout<<1;
                if(b[2]=='A' and d[2]=='B'){
                    cout<<1;
                }
                if(b[2]=='B' and d[2]=='A'){
                    cout<<1;
                }if(b[2]=='C' and d[2]=='B'){
                    cout<<1;
                }if(b[2]=='B' and d[2]=='C'){
                    cout<<1;
                }if(b[2]=='D' and d[2]=='F'){
                    cout<<1;
                }if(b[2]=='F' and d[2]=='D'){
                   cout<<1;
                }
                }else{cout<<0<<0;}
        }else{cout<<0;}
    }else{cout<<0<<0<<0<<0;}
    return 0;
}
