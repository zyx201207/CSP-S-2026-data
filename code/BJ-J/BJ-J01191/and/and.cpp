#include<bits/stdc++.h>
using namespace std;
int a[1000000],s[1000000],cnt;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
int n,m,sum=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];

}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
   if(a[i]==a[i+1])
   {
      sum++;
   }
if(sum==n)cout<<a[1];

if(sum==0)
{
    sort(a+1,a+n+1);
    cnt+=a[m]&a[m-1];
    cout<<cnt;

}
 else if(m==1)
{

    sort(a+1,a+n+1);
    cout<<a[n];


}
else if(m==n)
{

    for(int i=1;i<=n;i++)
    {
       s[i]=s[i-1]&a[i];
    }
    cout<<s[n];
}
else if(m==n&m==1&&n==1)
{

    cout<<1;
}
}
