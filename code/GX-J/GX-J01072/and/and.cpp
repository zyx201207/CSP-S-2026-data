#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int bit=29;bit>=0;bit--)
    {
       int t=ans|(1<<bit),c=0;
       for(int i=1;i<=n;i++)
       {
           if((a[i]&t)==t)
           {
               c++;
           }
           if(c>=m)
           {
               ans=t;
           }
       }
    }
    cout<<ans;
 return 0;
}
