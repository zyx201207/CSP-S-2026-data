#include<bits/stdc++.h>
using namespace std;
bool px(int a,int b)
{
    return a>b;
}
long long n,a[200005],m;
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
  }
  sort(a+1,a+1+n,px);
  cout<<a[m];
  return 0;
}
