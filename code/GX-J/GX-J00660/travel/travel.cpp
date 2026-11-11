#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int f=0;
if(c1==c2)cout<<1,f=1;
else cout<<0;
int f1=0,f2=0;
if(s1[0]==s2[0]&&s1[1]==s2[1]&&f==1)cout<<1,f1=1;
else cout<<0;
if(f1==0||(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='D'))cout<<0;
else cout<<1,f2=1;
if(f2==1&&abs(s2[2]-s1[2]==1))cout<<1;
else cout<<0;
return 0;
}
