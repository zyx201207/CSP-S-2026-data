#include <bits/stdc++.h>
using namespace std;
int mian(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a,b,c[100000005],q=0,l=0,p=0,l[10005],x=1;
cin>>a>>b;
for(int i=1;i<=b;i++){
    l[i]=x;
    x++;
}

for(int i=0;i<a-1;i++){
    cin>>c[i];
}
for(int i=0;i<a;i++){
   for(int y=0;y<a;y++){
    if(b=2){
      l=q;
      q=(c[i]&c[y]);
    if(p<max(l,q))
        p=max(l,q);


   }
}
cout<<p;
return 0;
}
