#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],lt[300005],nx[500005],ll[500005];
vector<int>v;
int qw(int x)
{
    if(ll[x]==-1)return 0;
    if(ll[x]!=0)return ll[x];
    for(int i=x-1;i>=1;i--)
    {
        if(nx[i]>x)
        {
            ll[x]=i;
            return i;
        }
    }
    ll[x]=-1;
    return 0;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        nx[lt[a[i]]]=i;
        lt[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int cnt=lt[i],lr=lt[i],p=qw(lt[i]);
        int f=0,g=0;
        while(p>0)
        {
            v.push_back(lr);
            if(f==0&&g==0)
            {
                cnt-=p;
            }
            else if(g==0)
            {
                cnt+=p;
            }
            int l=0,r=v.size()-1,q=n+1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nx[p]>v[mid])
                {
                    l=mid+1;
                    q=v[mid];
                }
                else
                {
                    r=mid-1;
                }
            }
            if(nx[p]<q||nx[p]==lt[i])
            {
                g=0;
                f=1-f;
            }
            else
            {
                g=1;
            }
            lr=p;
            p=qw(p);
        }
        v.clear();
        cout<<cnt<<" ";
    }
    return 0;
}
