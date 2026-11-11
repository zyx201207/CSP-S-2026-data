#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c,o,a,p,r,l;
    string s;
    string d;
    cin>>c>>s>>a>>d;
    for(int i=s.size();i>=1;i--){
        if(s[i]>='0'&&s[i]<='9'){
            o=s[i];
        }
    }
    for(int i=d.size();i>=1;i--){
        if(d[i]>='0'&&d[i]<='9'){
            p=d[i];
        }
    }
    for(int i=s.size();i>=1;i--){
        if(s[i]>='A'&&s[i]<='F'){
            r=s[i];
        }
    }
    for(int i=d.size();i>=1;i--){
        if(d[i]>='A'&&d[i]<='F'){
            l=d[i];
        }
    }
    if(c==a){
        cout<<1000;
    }
    else if(c==a&&o==p){
        cout<<1100;
    }
    else if(c==a&&r=='A'&&l=='A'||c==a&&r=='B'&&l=='A'||c==a&&r=='C'&&l=='A'){
        cout<<1010;
    }
    else if(c==a&&r=='A'&&l=='A'||c==a&&r=='A'&&l=='B'||c==a&&r=='A'&&l=='C'){
        cout<<1010;
    }
    else if(c==a&&r=='D'&&l=='D'||c==a&&r=='D'&&l=='F'){
        cout<<1010;
    }
    else if(c==a&&r=='D'&&l=='D'||c==a&&r=='F'&&l=='D'){
        cout<<1010;
    }
    else if(c==a&&abs(r-l)==1){
        cout<<1001;
    }
    else{
        cout<<1110;
    }
    return 0;
}
