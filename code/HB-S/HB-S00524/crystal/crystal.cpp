#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],cnt[N],ans;
int len;
int mx=0;
vector<pair<int,int>>e[N];
void lsh()
{
    sort(b+1,b+n+1);
    int it=unique(b+1,b+n+1)-b-1;
    len=it;
}
int id(int x)
{
    return lower_bound(b+1,b+len+1,x)-b;
}

void tsxz()
{
    for(int i=n-1;i>=1;i--)
    {
        m-=(a[n]-a[i]);
        if(m>0)ans++;
    }
    cout<<ans;
    return;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];

    if(n>5000&&a[n]==(a[2]-a[1])*(n-1)+a[1]&&a[n]==(a[3]-a[2])*(n-2)+a[2])
    {
        tsxz();
        return 0;
    }

    lsh();
    for(int i=1;i<=n;i++)cnt[id(a[i])]++;

    e[1].push_back({0,cnt[1]});
    mx=max(cnt[1],mx);
    for(int i=2;i<=len;i++)
    {
        ans=0;
        e[i].push_back({0,cnt[i]});
        ans+=cnt[i];
        int k=m;
        for(auto v:e[i-1])
        {
            bool flag=0;
            if(k>=(v.first+(b[i]-b[i-1]))*v.second)
            {
                e[i].push_back({(v.first+(b[i]-b[i-1])),v.second});
                k-=(v.first+(b[i]-b[i-1]))*v.second;
                ans+=v.second;
            }    
            else
            {
                if(k>=v.first+(b[i]-b[i-1]))
                {
                    e[i].push_back({v.first+(b[i]-b[i-1]),(k/(v.first+b[i]-b[i-1]))});
                    ans+=(k/(v.first+(b[i]-b[i-1])));    
                }
                flag=1;
            }
            if(flag)break;
        }
        mx=max(ans,mx);
    }

    cout<<mx;
    return 0;
}