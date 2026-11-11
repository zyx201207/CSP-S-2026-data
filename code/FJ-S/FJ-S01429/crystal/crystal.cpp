#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500006];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>1e8+1)
	{
		int gc=a[2]-a[1];
		int k=0;
		while((1+k)*k/2<m)
		{
			k+=gc;
		}
		cout<<min(n,k+1)<<endl;
		return 0;
	}
	int target,cnt=-1,cnt1=0,m1=m;
	for(int i=1;i<=n;i++)
	{
		target=a[i];
		if(target==a[i-1])
		{
			cnt1++;
			cnt=max(cnt,cnt1);
			continue;
		}
		cnt1=0; 
		for(int j=i;j>0;j--)
		{
			if(target-a[j]<=m1)
			{
				cnt1++;
				m1=m1-target+a[j];
			}
			else break;
		}
		cnt=max(cnt,cnt1);
		m1=m;
	}
	cout<<cnt;
	return 0;
}
