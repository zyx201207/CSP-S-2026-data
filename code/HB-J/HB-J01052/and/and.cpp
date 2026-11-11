#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("string.in","w",stdin);
   freopen("string.out","r",stdout);
   int n,m;
   cin>>n>>m;
   int a[n];
   for(int c=0;c<n;c++)
   {
       cin>>a[c];
   }
   if(m<=2)
   {
       cout<<m||n;
   }
return 0;
}
