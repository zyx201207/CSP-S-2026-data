#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    int c1,d1;
    char c2,d2;
    c1=c[0]-48;
    c1=c1*10;
    c1=c1+c[1]-48;
    d1=d[0]-48;
    d1=d1*10;
    d1=d1+d[1]-48;
    c2=c[2];
    d2=d[2];
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c1==d1){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((int)c2<=67&&(int)d2<=67){
        cout<<1;
    }else if((int)c2>=68&&(int)d2>=68){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((int)c2==(int)d2+1||(int)c2==(int)d2-1){
        cout<<1;
    }else{
        cout<<"0";
    }
    return 0;
}
