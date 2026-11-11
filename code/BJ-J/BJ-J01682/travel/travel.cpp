#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        x=(c[0]-'0')*10+(c[1]-'0');
        y=(d[0]-'0')*10+(d[1]-'0');
        if(x==y){
            cout<<1;
            if('A'<=c[2] && c[2]<='C' &&'A'<=d[2] && d[2]<='C'){
                cout<<1;
                if((c[2]=='A' && d[2]=='B')||(c[2]=='B' && d[2]=='C')){cout<<1;}
                else {cout<<0;}
            }else{
                if('D'<=c[2] && c[2]<='F' &&'D'<=d[2] && d[2]<='F'){cout<<11;}
                else {cout<<"00";}
            }
        }
        else {cout<<"000";}

    }
    else {cout<<"0000";}
    return 0;
}