#include<bits/stdc++.h>
using namespace std;
int main()
 {
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  long long n,m;
  cin>>n>>m;
  long long a[10001];
  for(int i=0;i<n;++i)
    cin>>a[i];
  sort(a+0,a+0+n);
  int ans=a[n-1];
  int z=n-m-1;
  for(int i=n-2;i>z;--i)
    ans&=a[i];
  cout<<ans;
  return 0;
 }
