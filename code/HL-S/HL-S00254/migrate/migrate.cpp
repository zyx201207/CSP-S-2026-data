#include<bits/stdc++.h>
#define int long long
using namespace std;
const int _=5e3+5;

int n,d[_][_],a[_],b[_][_],e[_][_],s[_][_];

signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  int c,T;
  cin>>c>>T;
  while(T--)
  {
    int ans=0,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j]=0,b[i][j]=0,e[i][j]=0,s[i][j]=0;
    for(int i=1;i<=n;i++)
    {
      int x=a[i],num=0;
      for(int j=i+1;j<=n;j++)
      {
        if(a[j]<=x)
          d[i][j]=num;
        else
        {
          e[i][num]=j-1;
          ++num;
          x=a[j-1]+l;
          if(a[j]<=x)
          {
            d[i][j]=num;
            b[i][num]=j;
          }
          else
            break;
        }
      }
      for(int j=i+1;j<=e[i][1];j++)
        s[i][j]=1;
      for(int j=b[i][2];j<=n;j++)
      {
        if(d[i][j]==0)
          break;
        for(int o=e[i][d[i][j]-1];o>=b[i][d[i][j]-1];o--)
        {
          if(a[j]-a[o]>l)
            break;
          s[i][j]+=s[i][o];
          if(s[i][j]>2)
            break;
        }
        if(s[i][j]==2)
          ++ans;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
