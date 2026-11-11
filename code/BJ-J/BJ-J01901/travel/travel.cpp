#include<bits/stdc++.h>
using namespace std;
#define int long long
char a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a0;
if(a1==a6&&a2==a7)cout<<1;
else cout<<0;
if(a1==a6&&a2==a7&a3==a8&&a4==a9)cout<<1;
else cout<<0;
if(a1==a6&&a2==a7&a3==a8&&a4==a9){
    if(a5=='A'&&a0=='B')cout<<1;
    else if(a5=='A'&&a0=='C')cout<<1;
    else if(a5=='B'&&a0=='C')cout<<1;
    else if(a5=='B'&&a0=='A')cout<<1;
    else if(a5=='C'&&a0=='A')cout<<1;
    else if(a5=='C'&&a0=='B')cout<<1;
    else if(a5=='D'&&a0=='F')cout<<1;
    else if(a5=='F'&&a0=='D')cout<<1;
    else cout<<0;
}
else cout<<0;
if(a1==a6&&a2==a7&a3==a8&&a4==a9){
    if(a5=='A'&&a0=='B')cout<<1;
    else if(a5=='B'&&a0=='A')cout<<1;
    else if(a5=='B'&&a0=='C')cout<<1;
    else if(a5=='C'&&a0=='D')cout<<1;
    else if(a5=='D'&&a0=='F')cout<<1;
    else if(a5=='F'&&a0=='D')cout<<1;
    else cout<<0;
}
else cout<<0;
return 0;
}
