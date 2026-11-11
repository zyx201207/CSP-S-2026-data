#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        int x=0,y=0,i=0,j=0;
        while(c[i]>='0'&&c[i]<='9')x=x*10+c[i++]-'0';
        while(d[j]>='0'&&d[j]<='9')y=y*10+d[j++]-'0';\
        if(x==y){
            cout<<1;
            char e=c[i],f=d[i];
            bool t=0;
            if(e=='A'&&f=='B')t=1;
            if(e=='A'&&f=='C')t=1;
            if(e=='B'&&f=='C')t=1;
            if(e=='D'&&f=='F')t=1;
            if(f=='A'&&e=='B')t=1;
            if(f=='A'&&e=='C')t=1;
            if(f=='B'&&e=='C')t=1;
            if(f=='D'&&e=='F')t=1;
            cout<<t;
            if(t){
                t=0;
                if(e=='A'&&f=='B')t=1;
                if(e=='B'&&f=='A')t=1;
                if(e=='B'&&f=='C')t=1;
                if(e=='C'&&f=='B')t=1;
                if(e=='D'&&f=='F')t=1;
                if(e=='F'&&f=='D')t=1;
                cout<<t;
            }
            else cout<<0;
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
