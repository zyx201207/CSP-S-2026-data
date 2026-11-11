#include<bits/stdc++.h>
using namespace std;
long long n,m,minn=9999999999999,mid,maxn;
struct jgt
{
long long nl,dj,sl,sd;}
a[1000010];
bool px(jgt x,jgt y)
{return x.nl<y.nl;}
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
scanf("%lld%lld",&n,&m);
for(long long i=1;i<=n;i++)
scanf("%lld",&a[i].nl);
sort(a+1,a+n+1,px);
a[1].dj=0; a[1].sl=1;  a[1].sd=1;
for(long long i=2;i<=n;i++)
{
a[i].dj=(a[i].nl-a[i-1].nl)*(i-1)+a[i-1].dj;
a[i].sl=a[i-1].sl+1;
a[i].sd=a[i-1].sd;
while(a[i].dj<m&&a[i].sd>=2)
{a[i].sd--; a[i].dj+=(a[a[i].sd+1].nl-a[a[i].sd].nl)*a[i].sd; a[i].sl++;}
if(a[i].dj>m) {a[i].sd++; a[i].dj-=(a[a[i].sd].nl-a[a[i].sd-1].nl)*(a[i].sd-1); a[i].sl--;}
}
maxn=a[1].sl;
for(long long i=2;i<=n;i++)
maxn=max(maxn,a[i].sl);
printf("%ld",maxn);
return 0;
} 
