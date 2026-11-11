#include<bits/stdc++.h>
using namespace std;

int n;
char b[2099399995];
struct node
{

    int id;
    long long a;
    char s;
}q[2000005];


int main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   cin>>n;
   long long x=0,ans=0;
   for(int i=1;i<=n;i++)
   {

       cin>>q[i].a>>q[i].s;
       q[i].id=i;
       x+=q[i].a;
       for(int j=1;j<=q[i].a;j++)
       {
           b[j]=q[i].s;
       }
   }

   if(x%2!=0)
   {
       for(long long i=1;i<=(x+1)/2;i++)
       {
            if(b[i]==b[x-i+1])
            {
                continue;
            }
            else
            {
                b[x-i+1]=b[i];
                ans++;
            }


       }
   }
   else if(x%2==0)
   {
       for(long long i=1;i<=x/2;i++)
       {
            if(b[i]==b[x-i+1])
            {
                continue;
            }
            else
            {
                b[x-i+1]=b[i];
                ans++;
            }
       }
   }
   cout<<ans;
   return 0;
}
