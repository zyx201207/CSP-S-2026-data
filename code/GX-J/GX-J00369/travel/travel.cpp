#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool c1,c2,c3;
    int n1,m1;
    string n2,m2,a,b,c,d,f;
    cin>>n1>>n2>>m1>>m2;
    c1=0;
    c2=0;
    c3=0;
    a="A";
    b="B";
    c="C";
    d="D";
    f="F";
    if(n1==m1){
        cout<<"1";
        c1=1;
    }else{
        cout<<"0";
    }if(n2[0]==m2[0] && n2[1]==m2[1] && c1==1){
        cout<<"1";
        c2=1;
    }else{
        cout<<"0";
    }if((n2[2]==a[0] || n2[2]==b[0] || n2[2]==c[0]) && (m2[2]==d[0] || m2[2]==f[0])){
        cout<<"0";
    }else{
        if(c2==1){
            cout<<"1";
            c3=1;
        }else{
            cout<<"0";
        }
    }if(n2[2]+1==m2[2] && c3==1){
        cout<<"1";
    }else{
        cout<<"0";
    }return 0;
}
