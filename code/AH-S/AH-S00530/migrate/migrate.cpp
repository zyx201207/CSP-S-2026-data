#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+1;
int c,T;
int n,d,a[N],ans;
queue<pair<int,int>> q;
unordered_map<int,bool> rt;
bool check(int l,int r)
{
    for(int i=l+1;i<=r;i++)
        if(a[i]-a[i-1]>d)
            return false;
    int cnt=0x7f7f7f7f;
    unordered_map<int,int> mp;
    q.push({a[l],0});
    while(!q.empty())
    {
        int tu=q.front().first;
        int step=q.front().second;
        q.pop();
        if(step>cnt)
            continue;
        if(tu==a[r])
        {
            mp[step]++;
            cnt=min(cnt,step);
            continue;
        }
        for(int i=1;i<=d;i++)
        {
			int neww=i+tu;
            if(neww>a[r])
                break;
            if(rt[neww]==false)
                continue;
            q.push({neww,step+1});
        }
    }
    if(mp[cnt]!=2)
        return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        bool flop=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i],rt[a[i]]=true;
            if(i>2&&a[i]-a[i-1]!=a[2]-a[1])
				flop=false;
		}
		if(a[n]<=d||n<4)
		{
			cout<<0<<'\n';
			continue;
			}
		if(flop==true)
		{
			if(a[2]-a[1]>d)
				cout<<0<<'\n';
			else
				cout<<n-3<<'\n';
			continue;
		}
        for(int u=1;u<n-1;u++)
            for(int v=u+2;v<=n;v++)
            {
                if(check(u,v)==true)
                    ans++;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
