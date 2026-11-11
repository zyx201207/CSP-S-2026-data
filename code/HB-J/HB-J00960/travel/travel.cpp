#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else cout<<0;
    string a,b;
    char c,d;
    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    c=s1[2];
    d=s2[2];
    if(c1==c2&&a==b){
        cout<<1;
    }
    else cout<<0;
    if(c1==c2&&a==b&&((c>='A'&&c<='C')&&(d>='A'&&d<='C'))||((c>='D'&&c<='F')&&(d>='D'&&d<='F')))
        cout<<1;
    else cout<<0;
    if(c1==c2&&a==b){
        if((c>='A'&&c<='C')&&(d>='A'&&d<='C')){
            if(int(c)+1==int(d)||int(d)+1==int(c))
                cout<<1;
            else cout<<0;
        }else if((c>='D'&&c<='F')&&(d>='D'&&d<='F'))
            cout<<1;
        else cout<<0;

    }else cout<<0;
    return 0;
}
