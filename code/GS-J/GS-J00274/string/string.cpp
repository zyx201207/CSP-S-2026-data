#include <bits/stdc++.h>
using namespace std;
int main()
{
      freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
      int n,a,d =0,ans=0;
      char b;
      cin >> n;
      string c = "";
      for(int i = 1;i<=n;i++)
      {
          cin >> a >> b;
          d+=a;
          for(int i = 1;i<=a;i++)
          {
              c+=b;
          }
      }
      for(int i = 0;i<d/2;i++)
      {
           if(c[i]!=c[d-i])
           {
               ans++;
           }
      }
      cout << ans;
      return 0;
}
