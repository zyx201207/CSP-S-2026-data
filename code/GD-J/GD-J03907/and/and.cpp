#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
   int ans=-1;
   if(m==2)
   {
       for(int i=1;i<=n-1;i++)
       {
       ans=max(ans,a[i]&a[i+1]);
       }
   }
   else
    {
        sort(a+1,a+n+1);
        m-=1;
        while(m--)
        {
            ans=a[n];
            ans&=a[n-1];
            n--;
        }
    }
   cout<<ans;
   return 0;
}
