#include<bits/stdc++.h>
using namespace std;
const int _=1e5+5;

int n,k;

void solve()
{
  ios::sync_with_stdio(0);cin.tie(0);
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;
    cin>>u>>v;
  }
  if(k==1)
  {
    int x;
    x=n-k;
    int y=x/2;
    if(y*2<x)
      ++y;
    cout<<y<<"\n";
  }
  else
  {
    int l=1,r=n;
    while(l<=r)
    {
      int mid=(l+r)>>1;
      cerr<<l<<" "<<r<<"\n";
      if(mid*4+k<n)
        l=mid+1;
      else
        r=mid-1;
    }
    cout<<(r+1)<<"\n";
  }
}

int main()
{
  int c,T;//ceshidian
  cin>>c>>T;
  while(T--)
    solve();
  return 0;
}
