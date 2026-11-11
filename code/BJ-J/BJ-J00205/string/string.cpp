#include <bits/stdc++.h>
using namespace std;

long long n,x,z=0,s;
char y;
long long a,b[200005];
string nl;
int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>x>>y;
       x+=z;
       for(int j=z;j<x;j++)
       {
           nl[j]=y;
           z++;
       }
   }
   if(x%2==1)
   {
        for(int i=0,j=x-1;i<(x-1)/2,j>=(x+1)/2;i++,j--)
        {
            if(char(nl[i])!=char(nl[j]))
            {
                a++;
            }

        }

   }
   else
   {

       for(int i=0,j=x-1;i<x/2,j>=x/2;i++,j--)
        {
            if(nl[i]!=nl[j])
            {
                a++;
            }
        }
   }
   cout<<a;
    return 0;
}
