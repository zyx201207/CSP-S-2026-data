#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i]>>c[i];
     }
     int l=1,r=n;
     long long ans=0;
     while(l<r)
     {
         long long t=min(a[l],a[r]);
         if(c[l]!=c[r])
         {
          ans+=t;
         }
         a[l]-=t;
         a[r]-=t;
         if(a[l]==0)
         {
             l++;
         }
         if(a[r]==0)
         {
             r--;
         }
     }
     cout<<ans;
    return 0;
}

