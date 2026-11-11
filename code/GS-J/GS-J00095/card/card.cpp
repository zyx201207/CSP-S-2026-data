#include<bits/stdc++.h>
using namespace std;

vector<int> v(0);
int n,m;
int a[500005],ans[300005];

int f(int x)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x) return i+1;
    }
    return -1;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int k=f(a[j]);
          if(k==-1) v.push_back(a[j]);
          else
          {
              for(int p=k+1;p<=n;p++)
              {
                  v[p]=0;
              }

          }
        }
        for(int q=0;q<=v.size();q++)
        {
            ans[v[q]]++;
        }
    }
    for(int i=1;i<=m;i++)
   {
       cout<<ans[i]<<' ';
   }
    return 0;

}
