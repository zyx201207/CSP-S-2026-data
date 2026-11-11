#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],f[20010][20010],w[200010],maxl;
int wz[2],yys,jd,ejz_ws;
bool ejz[100][2];
int yh(int x,int y)
{
wz[0]=1; wz[1]=1;
while(x!=0)
{
ejz[wz[0]][0]=x%2;
x/=2; wz[0]++;
}
while(y!=0)
{
ejz[wz[1]][1]=y%2;
y/=2; wz[1]++;
}
yys=0;
jd=min(wz[0],wz[1])-1;
ejz_ws=1;
for(int i=1;i<=jd;i++)
{yys=yys+ejz_ws*(ejz[i][0]&&ejz[i][1]); ejz_ws*=2;}
return yys;
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)
{scanf("%d",&a[i]); f[i][i]=a[i];}
for(int i=1;i<=m;i++)
for(int j=1;j<=n-i;i++)
f[j][j+i]=yh(f[j][j+i-1],a[i+j]);
if(m==n)
{printf("%d",f[1][n]); return 0;}
else if(m==1)
{
int maxn=0;
for(int i=1;i<=n;i++)
maxn=max(maxn,a[i]);
printf("%d",maxn);
return 0;
}
else if(m==2)
{
int maxn=0;
for(int i=1;i<=n-1;i++)
maxn=max(maxn,f[i][i+1]);
for(int i=1;i<=n-2;i++)
for(int j=i+2;j<=n;j++)
maxn=max(maxn,yh(a[i],a[j]));
printf("%d",maxn);
return 0;
}
return 0;
}
