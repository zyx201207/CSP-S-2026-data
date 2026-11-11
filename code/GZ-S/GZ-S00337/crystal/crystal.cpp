//黄志航 GZ-S00337 贵阳市第九中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 cout.tie(0);
 cin.tie(0);
 int n,m;
 cin>>n>>m;
 int a[n+5];
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n);
 int r=1,l=2;
 int ans=1;
 while(1)
 {
  long long x=0;
  int y=1;
  for(int i=r;i<l;i++)
  if(a[i]<=a[l])
  {
   x+=a[l]-a[i];
   y++;
  }
  if(x<=m)
  {
   ans=max(y,ans);
   if(l==n) r++;
   else l++;
  }
  else r++;
  if(l==n&&r==n) break;
 }
 cout<<ans<<endl;
}
