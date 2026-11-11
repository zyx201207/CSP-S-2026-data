#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],jsq[10010];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
scanf("%ld%ld",&n,&m);
for(int i=1;i<=n;i++)
{scanf("%ld",&a[i]); if(a[i]!=a[i-1]) jsq[a[i]]+=i;
else
{for(int j=1;j<=i;i++) jsq[j]=0; jsq[i]=1;}
}
for(int i=1;i<=m;i++)
printf("%ld ",jsq[i]);
return 0;
}
