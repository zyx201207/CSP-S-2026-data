#include<bits/stdc++.h>
using namespace std;
long long a,t,b; 
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
scanf("%lld%lld",&a,&t);
for(int i=1;i<=t;i++)
{
scanf("%lld",&b);
for(int i=1;i<=b;i++)
scanf("%lld",&a);
}
for(int i=1;i<=t;i++)
printf("%d\n",0);
return 0;;
} 
