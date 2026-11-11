#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll q[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
     cin>>n>>m;
       ll l=0,r=INT_MIN;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         max(r,a[i]);
     }
     sort(a+1,a+1+n);
     ll sum=1,maxm=0;
     q[1]=abs(a[1]);
     for(int i=2;i<=n;i++)
     {
        q[i]=a[i]-a[i-1];
     }
     ll ma=0;

     for(ll i=1;i<=n;i++)
     {
         for(ll j=i+1;j<=n;j++)
         {
             ma+=q[j];
         if(ma>m)
         {
           break;
         }
         sum++;
         }
         maxm=max(sum,maxm);
         sum=1;
         ma=0;

     }
     cout<<maxm;
    return 0;
}
