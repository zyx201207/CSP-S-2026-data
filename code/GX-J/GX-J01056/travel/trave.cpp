#include<bits/stdc++.h>
using namespace std;
int n,m;
string t1,t2;
int main(){
    freopen("trave.in","r",stdin);
    freopen("trave.out","w",stdout);
    cin>>n>>t1>>m>>t2;
    if(n==m) cout<<1;
    else cout<<0;
    if(t1[0]+t1[1]==t2[0]+t2[1]&&n==m) cout<<1;
    else cout<<0;
    if(t1[0]+t1[1]==t2[0]+t2[1]&&n==m){
        if((t1[2]>='A'&&t1[2]<='C'&&t2[2]>='A'&&t2[2]<='C')||(t1[2]>'C'&&t1[2]<='F'&&t2[2]>'C'&&t2[2]<='F')) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(t1[0]+t1[1]==t2[0]+t2[1]&&n==m){
        if ((t1[2]<='C'&&t2[2]<='C')||(t1[2]>'C'&&t2[2]>'C')){
        if((t1[2]=='A'&&t2[2]=='B')||(t1[2]=='B'&&t2[2]=='C')||(t2[2]=='D'&&t1[2]=='F')||(t2[2]=='A'&&t1[2]=='B')||(t2[2]=='B'&&t1[2]=='C')||(t2[2]=='D'&&t1[2]=='F')&n==m) cout<<1;
        else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;
}


