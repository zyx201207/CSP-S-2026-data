#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int b[k+1],a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,z=0;
    while(k>0)
   {
       a[n]&=a[n-z];
       k--;
       z++;
   }
   cout<<a[n];
    return 0;
}
