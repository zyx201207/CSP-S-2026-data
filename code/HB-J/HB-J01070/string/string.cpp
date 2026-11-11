#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     string c;
     int n;
     cin>>n;
    int h=0;
      cout<<"0";
     for(int i=1;i<=n;i++){
         int a;
         cin>>a;
         cin>>c[i];
         char b=c[i];
         for(int i=2;i<=a;i++)
         c[i]+=b;
         h+=a;
     } 
     if(h==1)
     {
     cout<<0;
     return 0;
     }
     if(h==2)
     {
     cout<<0;
     return 0;
     }
    num=h/2;
    int ans=0;
    for(int i=1;i<=num;i++)
    {
        for(int j=h,j>=num;j--)
        {
            if[c[i]!=c[j]]
            ans++;
        }
    }
    cout<<ans;
    return 0;
}