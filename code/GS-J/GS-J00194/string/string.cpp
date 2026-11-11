#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],r,lf,rsy,lsy,wz;
long long l=0,jsq=0;
char c[200010];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
scanf("%d",&n); r=1; lf=n;
for(long long i=1;i<=n;i++)
{scanf("%d%s",&a[i],&c[i]); l+=a[i];}
rsy=a[1]; lsy=a[n];
while(1)
{
if(rsy<=lsy)
{
if(c[r]!=c[lf])
{
if(wz+rsy>=l/2) {jsq+=l/2-wz;}
else {jsq+=rsy;}
}
if(wz+rsy>=l/2) break;
lsy-=rsy; wz+=rsy; rsy=a[++r];
}
else
{
if(c[r]!=c[lf])
{
if(wz+lsy>=l/2) {jsq+=l/2-wz;}
else {jsq+=lsy;}
}
if(wz+lsy>=l/2) break;
rsy-=lsy; wz+=lsy; lsy=a[--lf];
}
}
cout<<jsq;
return 0;
}
