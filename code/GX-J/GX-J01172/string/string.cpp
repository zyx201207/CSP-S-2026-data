#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,ma,sum=0;
string s;
struct ss{
   ll gs;
   char zf;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll sss=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].gs>>a[i].zf;
        ma+=a[i].gs;
        if(a[i].zf==a[i-1].zf) sss++;
    }
   if(sss==n)
   {
       cout<<0;
       return 0;
   }
    ll mid;
     if(ma%2==0)
      mid=ma/2;
    else  mid=ma/2+1;
    ll ls=0;
    char zz;
      for(ll i=1;i<=n;i++)
      {
          ls+=a[i].gs;

          if(ls>=mid)
          {
            zz=a[i].zf;
            break;
          }


      }
      ll l=1,r=n,duo=0;
      while(l<=r)
      {
          if(a[l].zf!=a[r].zf)
          {
              if(a[l].gs>=a[r].gs)
              {
                  sum+=a[r].gs;
                  a[l].gs-=a[r].gs;
                      a[r].gs=0;
              }
              else
              {
                  sum+=a[l].gs;
                  a[r].gs-=a[l].gs;
                  a[l].gs=0;
              }
          }
          else
          {
              if(a[l].gs>a[r].gs)
              {
                  a[l].gs-=a[r].gs;
              a[r].gs=0;
              }
                else {
                    a[r].gs-=a[l].gs;
                    a[l].gs=0;
                }
          }
          if(a[l].gs==0) l++;
          if(a[r].gs==0) r--;
      }
      cout<<sum;
     return 0;

}
