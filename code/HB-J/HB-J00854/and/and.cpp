#include<bits/stdc++.h>
using namespace std;
int a[10001];
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int ans=0,ac=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
       if(m==2)
        {
          ans=a[i]&a[i+1];
          if(ac<=ans)
          {
              ac=ans;
          }
        }
    }
    cout<<ac;
    return 0;
}
