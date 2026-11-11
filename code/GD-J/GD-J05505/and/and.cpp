
#include<bits/stdc++.h>
using namespace std;

const int MAXN=(int)2e5+1000;
int n,m;
long long ans=-1;
long long a[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long mask=0;mask<(1<<n);mask++)
	{
		long long copy=mask;
		int cnt=0;
		while(copy)
		{
			if(copy&1)cnt++;
			copy>>=1;
		}
		if(cnt!=m)continue;
		copy=mask;
		long long res=-1;
		int idx=0;
		while(copy)
		{
			idx++;
			if(copy&1)
			{
				res=res&a[idx];
			}
			copy>>=1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
