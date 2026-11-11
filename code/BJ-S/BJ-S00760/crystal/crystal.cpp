#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,INF=0x3f3f3f3f;
struct node
{
    int dis,now;
    friend bool operator<(const node &a,const node &b)
    {
        return a.now<b.now;
    }
}a[N];
signed main()
{
   freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  //  priority_queue<node>q;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].now;
    }
    sort(a+1,a+1+n);
    int ans=n,cnt=0;
    int max_a=-INF;
    for(int i=1;i<=n;i++)
    {
        max_a=max(max_a,a[i].now);
    }
   for(int i=1;i<=n;i++)
    {
        a[i].dis=max_a-a[i].now;
    }
    for(int i=1;i<=n;i++)
    {
        cnt+=max_a-a[i].now;
    }
    int k=n;
    k--;
    while(cnt>m)
    {
        cnt-=a[k].dis*k;
        int cur=a[k].dis;
        for(int j=k;j>=1;j--)
        {
            a[j].dis=a[j].dis-cur;
        }
        k--;
        ans--;
    }

   cout<<ans;
}
