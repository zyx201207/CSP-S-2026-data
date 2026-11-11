#include <bits/stdc++.h>
using namespace std;
int main()
{
      freopen("card.in","r",stdin);
      freopen("card.out","w",stdout);
      int n,m,a[100005],c[100005],p;
      cin >> n >> m;
      for(int i = 1;i<=n;i++)
      {
          cin >> a[i];
      }
      for(int i = 1;i<=m;i++)
      {
          p = 1;
          for(int j = n;j>i;j++)
          {
              c[p] = a[j];
              for(int z = 1;i<=n-i;z++)
              {
                  if(c[z] == c[j])
                  {
                      break;
                  }
              }
              p++;
          }
          p=0;
          for(int j = 1;j<=n-i;j++)
          {
              if(c[j] == i)
              {
                  p++;
                  break;
              }
          }
          cout << p << " ";
      }
      return 0;
}
