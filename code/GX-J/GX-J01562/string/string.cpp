#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     int n,m,a,b[9999],max=0;
     cin>>n>>m;
     for(int i=1;i<=n;i++)
     {
       cin>>a;
       max+=b[i];
     }
     cout<<max+max;
     return 0;
}


