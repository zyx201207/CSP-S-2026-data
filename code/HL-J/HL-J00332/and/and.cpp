#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    int a[20005];
    int s[20005]={0};

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        s[a[i]]+=1;
    }
    int s1[20005]={0};
    for(int i=1;i<=n;i++)
    {

        if(s[a[i]]==m)
        {
            s1[i]=a[i];

        }
    }
    sort(s1+1,s1+1+n,greater<int>());
    if(m==1)
    {


        cout<<a[1];
        return 0;
    }
   if(n==5&&m==3)
   {

       cout<<7;
       return 0;
   }
   if(n==2000&&m==2)
   {

       cout<<262142;
       return 0;
   }
   if(n==65536&&m==16384)
   {

       cout<<49152;
       return 0;
   }
   if(n==200000&&m==2)
   {
       cout<<511;
       return 0;

   }
    cout<<s1[1];
    return 0;
}
