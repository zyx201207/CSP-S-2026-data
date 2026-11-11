#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
map<int,int>mp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int i,j,k,d;
    bool flag=true;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
            d=a[i]-a[i-1];
        else if(i>=2)
        {
            if(a[i]-a[i-1]!=d)
                flag=false;
        }
    }
    if(flag)
        cout<<signed(sqrt(m*2.0/d))<<endl;
    else
    {
        for(i=1;i<=n;i++)
            mp[a[i]]++;
        int last=0;
        for(auto kv:mp)
        {
            if(last==0)
            {
                last=kv.first;
                continue;
            }
            m-=(kv.first-last)*mp[last];
            mp[kv.first]+=mp[last];
            mp[last]=0;
            last=kv.first;
            if(m<0)
                break;
        }
        for (auto kv:mp)
            if (kv.second)
            {
                cout<<kv.second-1<<endl;
                break;
            }
    }
}
