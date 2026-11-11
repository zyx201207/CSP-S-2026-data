#include <bits/stdc++.h>
using namespace std;
int mian(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a,b,zz,zv,l=0;
string s,g;
cin>>a;
for(long long i=1;i<=a;i++){
  cin>>b>>g;
  for(long long d=1;d<=b;d++)
        s+=g;
}
g=s;
reverse(s.begin(),s.end());
if(g==s)
cout<<0;
zz=g.size();
for(long long l=0;l<zz;l++){
  zv=max(s[l],g[l]);
   if(zv==0)
     l++;
}
if(zz-l==1)
    cout<<zz;
else
cout<<(zz-l)/2;


return 0;
}
