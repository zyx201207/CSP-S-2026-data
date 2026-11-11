#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
bool f1=1,f2=1,f3=1;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1) cout<<1;
    else{
        cout<<0;
        f1=0;}
    if(f1&&a2[0]==b2[0]&&a2[1]==b2[1]) cout<<1;
    else{
        cout<<0;
        f2=0;}
    if(!f2||(a2[2]=='C'&&b2[2]=='D')||(a2[2]=='D'&&b2[2]=='C')){
        cout<<0;
        f3=0;}
    else cout<<1;
    if(f3&&(int(a2[2])+1==int(b2[2])||int(b2[2])+1==int(a2[2]))) cout<<1;
    else cout<<0;
    return 0;
}