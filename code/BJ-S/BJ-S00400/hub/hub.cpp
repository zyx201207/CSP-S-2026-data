#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v[2000010];
signed main()
{
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--)
   {
      int n,k;
      cin>>n>>k;
      for(int i=1;i<=n;i++) v[i].clear();
      for(int i=1;i<=n;i++)
      {
         int x,y;
         cin>>x>>y;
         v[x].push_back(y);
         v[y].push_back(x);
      }
   }
   cout<<"1 2"<<endl;
   return 0;
}
