#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int lt;
struct jgt
{
long long tx,sj;
int ck[20010];
}a[20010];
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
for(int i=1;i<=m;i++) scanf("%d",&x);
for(int i=1;i<=n;i++)
{
scanf("%lld",&a[i].tx);
for(int j=1;j<=a[i].tx;j++)
{
scanf("%d",&a[j].ck);
scanf("%lld",&a[j].sj);
}
}
for(int i=1;i<=q;i++)
{scanf("%lld%lld",&x,&y); printf("%lld\n",x+y);}
return 0;
} 
