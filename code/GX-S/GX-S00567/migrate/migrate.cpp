#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long

using namespace std;
int c,t;
int a[5005];
int u=0,sum=0;
int n,d;
void dfs(int x,int y,int mn)
{
   if(x==y)
   {
     if(mn==u) {sum++; return ;}
     if(mn<u) {u=mn; sum=1;}
     return ;
   }
   for(int i=x+1;i<=y;i++)
     if(a[i]-a[x]<=d) dfs(i,y,mn+1);
}
int main()
{
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   scanf("%d%d",&c,&t);
   while(t--)
   {
     n=0,d=0;
     scanf("%d%d",&n,&d);
     memset(a,0,sizeof(a));
     for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     ll ans=0;
     for(int i=1;i<=n;i++)
       for(int j=i+3;j<=n;j++)
       {
         u=n+1,sum=0;
         dfs(i,j,0);
         if(sum==2) ans++;
       }
     cout<<ans<<endl;
   }
   return 0;
}

