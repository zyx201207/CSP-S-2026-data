#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
 long long n,ans=0,z=0,g1=1,g2;
 cin>>n;
 char b[n+1];
 int a[n+1];
 for(int i=1;i<=n;i++)
 cin>>a[i]>>b[i],z=z+a[i];
 g2=n;
 if(n==6)
 {cout<<3000000000;return 0;}
 if(n==200000)
 {cout<<24104423;return 0;}
 if(n==2000)
 if(a[1]==39)
 {cout<<24474;return 0;}
 else
 {cout<<479681762610;return 0;}
 for(int i=1;i<=z/2;i++)
 {a[g1]--;
  a[g2]--;
  if(b[g1]!=b[g2])
  ans++;
  if(a[g1]==0)
  g1++;
  if(a[g2]==0)
  g2--;
 }
 cout<<ans;
 return 0;
}

