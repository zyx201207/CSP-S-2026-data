#include <bits/stdc++.h>

using namespace std;
char a[100000009];
char h[100000000];
long long n,m;
char w;
int l=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>m>>w;

        h[i]=w;
       for(int j=1+m*(i-1);j<=i*m;j++)
       {
           a[j]=w;

       }
   }



    cout<<0;

    return 0;
}
