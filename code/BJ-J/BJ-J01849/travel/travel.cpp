#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;
    char x,y;
    cin>>a>>b>>x>>c>>d>>y;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(b==d){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if((x=='A'&& y=='B')or(x=='A'&& y=='C')or(x=='B'&& y=='C')or(x=='B'&& y=='A')or(x=='C'&& y=='A')or(x=='C'&& y=='B')||(x=='D'&& y=='F')or(x=='F'&& y=='D')){
        cout<<1;
    }
    else{
        cout<<0<<0;
        return 0;
    }
    if((x=='A' && y=='B')or(x=='B' && y=='C')or(x=='D' && y=='F')or(x=='F' && y=='D')){
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
