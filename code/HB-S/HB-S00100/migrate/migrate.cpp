#include <bits/stdc++.h>
using namespace std;
int c,t;

int main()
{
    freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
     int n,d;
     int canfly=0;
     int minfly=0;
     int a[100001]={0};
     int ans=0;
     cin>>c>>t;
     for(int i=0;i<t;i++)
     {
         canfly=0;
         minfly=0;
         ans=0;
         a[100001]={0};
         cin>>n>>d;
         for(int j=0;j<n;j++)
         {
             cin>>a[j];
         }
         canfly=d/(a[1]-a[0]);
         if((a[n-1]-a[0])%canfly==0)
         {
             minfly=(a[n-1]-a[0])/canfly;
         }
         else
         {
             minfly= minfly=(a[n-1]-a[0])/canfly+1;
         }
        if(minfly!=2)
        {
            cout<<0<<endl;
        }

        else
        {
            for(int j=0;j<n;j++)
            {
                if(j+3<n)
                {
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
     }
     return 0;
}
