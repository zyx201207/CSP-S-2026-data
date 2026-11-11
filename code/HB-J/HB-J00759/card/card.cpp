#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n=0,m=0,a[500005],ans[300005];
vector<ll> dt;
ll p=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        dt.clear();
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<dt.size();k++)
            {
                if(dt[k]==a[j])
                {
                    dt.erase(dt.begin()+k,dt.end());
                    break;
                }
            }
            dt.push_back(a[j]);
        }
        for(int i=0;i<dt.size();i++)
        {
            ans[dt[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
	return 0;
}

