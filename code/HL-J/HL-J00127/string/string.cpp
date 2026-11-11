#include<bits/stdc++.h>
using namespace std;
bool mt(int a,int b)
{

    return a>b;
}
int main()
{
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     int n,m;
     cin>>n>>m;
     int a[n]={0};
     for(int i=0;i<n;i++)
     {

         cin>>a[i];
     }
     if(m==1)
     {

         sort(a,a+n,mt);
         cout<<a[0];
         return 0;
     }
     else if(m==n)
     {

         int num=0;
         for(int i=0;i<n-1;i++)
         {

             num=max(num,a[i]&a[i+1]);

         }
         cout<<num;
         return 0;
     }
     else if(m==2)
     {

         int num=0;
         for(int i=0;i<n;i++)
         {



                 num=max(num,a[i]&a[i+2]);

         }
         cout<<num;
     }




    return 0;
}
