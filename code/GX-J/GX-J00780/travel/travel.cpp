#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w,stdout);
string c1[4]=" ",c2[4]=" ",s2[4]=" ",s1[4]=" ";
cin>>c1>>" ">>s1>>" ">>c2>>" ">>s2;
if(c1==c2)
cout<<"1";else cout<<"0000";
for(int i=0;i<=1;i++){
if(s1[i]==s2[i])
cout<<"1";
else cout<<"0";}
if(s1[2]-s2[2]<=2&&s1[2]-s2[2]>-3)
cout<<"1";
else cout<<"0";
if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
cout<<"1";
else cout<<"0";




return 0;}
