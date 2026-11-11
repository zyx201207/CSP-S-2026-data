#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],nxt[2000001],ind[2000001],ind2[2000001],ind3[2000001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
       {
       scanf("%lld%lld",&n,&d);
       for(int i=1;i<=n;i++)scanf("%lld",&x[i]),ind[i]=ind2[i]=ind3[i]=0;
       long long r=n,ans=0;
       for(int i=n;i>=1;i--)
           {
           while(r>i&&x[r]>x[i]+d)r--;
           nxt[i]=r;
           if(nxt[i]!=i)ind[nxt[i]]++;
           }
       for(int i=1;i<=n;i++)
           if(ind[i]!=0)
              {
              int p1=i-1,p2=i-2;
              if(p1<1||nxt[p1]<=i)
                 {
                 ans+=1ll*(nxt[i]-i)*ind2[i];
                 ind[nxt[i]]+=ind[i],ind2[nxt[i]]+=ind2[i],ind[nxt[i]]+=ind3[i];
                 continue;
                 }
              else if(p2<1||nxt[p2]<=i)
                 {
                 ans+=1ll*(nxt[p1]-i)*ind[i];
                 ans+=1ll*(nxt[i]-nxt[p1])*ind2[i];
                 if(nxt[i]-nxt[p1]>=2)ind[nxt[i]]+=ind[i],ind[nxt[i]]+=ind3[i];
                 if(nxt[i]-nxt[p1]==1)ind3[nxt[i]]+=ind[i],ind3[nxt[i]]+=ind3[i];
                 if(nxt[i]-nxt[p1]>=1)ind2[nxt[i]]+=ind2[i];
                 if(nxt[p1]==nxt[i])ind2[nxt[i]]+=ind[i];
                 }
              else
                 {
                 ans+=1ll*(nxt[p1]-nxt[p2])*ind[i];
                 ans+=1ll*(nxt[i]-nxt[p1])*ind2[i];
                 if(nxt[i]-nxt[p1]>=2)ind[nxt[i]]+=ind[i],ind[nxt[i]]+=ind3[i];
                 if(nxt[i]-nxt[p1]==1)ind3[nxt[i]]+=ind[i],ind3[nxt[i]]+=ind3[i];
                 if(nxt[i]-nxt[p1]>=1)ind2[nxt[i]]+=ind2[i];
                 if(nxt[p1]==nxt[i]&&nxt[p1]!=nxt[p2])ind2[nxt[i]]+=ind[i];
                 }
              }
       printf("%lld\n",ans);
       }
    return 0;
}
