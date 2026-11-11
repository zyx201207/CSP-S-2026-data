#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N=5e5+5;
ll n,m,a[N],cnt[N],ans=0;
vector<ll>v;
ll find(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	v.push_back(-1e12-1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		cnt[find(a[i])]++;
	}
	ll l=1,num=0,cntl=0,sum=0;
	ans=cnt[1];
	for(int i=2;i<v.size();i++)
	{
		num+=cnt[i-1];
		sum+=num*(v[i]-v[i-1]);
		while(l<i&&sum>m)
		{
			if(sum-cntl*(v[i]-v[l])>=m)
			{
				sum-cntl*(v[i]-v[l]);
				l++;
				cntl=cnt[l];
			}
			else
			{
				sum-=cntl*(v[i]-v[l]);
				cntl-=(sum-m)/(v[i]-v[l]);
				sum+=cntl*(v[i]-v[l]);
			}
			if(l<i)ans=max(ans,num);
		}
	}
	cout<<ans;
	return 0;
 } 
