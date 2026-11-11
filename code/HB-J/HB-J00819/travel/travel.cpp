#include<bits/stdc++.h>
using namespace std;
int ai=1,bi=1,di=1,fi=1;
void a1(string a,string b){
    if(a!=b){
        ai=0;
        cout<<"0000";
        return;
    }
}
void a2(string a,string b){
    if(a[1]!=b[1] && ai){
        bi=0;
        cout<<"1000";
        return;
    }
}
void a3(string a,string b){
    char m=a[2];
    char n=b[2];
    int c=0,d=0;
    if(m=='D' || m=='F')c='1';
    if(n=='D' || n=='F')d='1';
    if(c!=d && ai && bi){
        di=0;
        cout<<"1100";
        return;
    }
}
void a4(string a,string b){
    char m=a[2];
    char n=b[2];
    if(m=='F')m='E';
    if(n=='F')n='E';
    int c=m-n;
    if(c<0)c*=-1;
    if(c!=1 && ai && bi && di){
        fi=0;
        cout<<"1110";
        return;
    }
}
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,m,n;
    cin>>a>>m>>b>>n;

    a1(a,b);
    a2(m,n);
    a3(m,n);
    a4(m,n);
    if(ai && bi && fi && di)
        cout<<"1111";
    return 0;
}
