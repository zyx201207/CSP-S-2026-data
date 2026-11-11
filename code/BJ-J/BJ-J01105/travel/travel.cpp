#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a,b;
char c,d;
int e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    a=a+s1[1]+s1[0];
    b=b+s2[1]+s2[0];
    c=s1[2];
    d=s2[2];
    e=c-'A';
    f=d-'A';
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a==b&&c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(b==a&&c1==c2&&((c<='C'&&d<='C')||(c>'C'&&d>'C'))){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(b==a&&c1==c2&&((c<='C'&&d<='C')||(c>'C'&&d>'C'))&&abs(e-f)==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
