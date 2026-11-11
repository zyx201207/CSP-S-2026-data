#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[550000],b[550000],s[550000];
map<int,int>mp;
map<int,int>num;
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int len=0;
	for (auto it:mp)
	{
		len++;
		num[len]=it.first;//能量 
		b[len]=it.second;//数量
		s[len]=s[len-1]+b[len]; 
	}
	int l=1,r=1;
	int sum=0,now=b[1];//花费，现在数量 
	while (r<len)
	{
		r++;
		sum+=(s[r-1]-s[l]+b[l])*(num[r]-num[r-1]);
		now+=b[r];
		//cout<<sum<<' '<<now<<'\n';
		while (sum>m&&l<r)
		{
			int cnt=(sum-m)/(num[r]-num[l]);//数量
			if ((sum-m)%(num[r]-num[l])!=0)
				cnt++;
			cnt=min(cnt,b[l]);
			int energy=cnt*(num[r]-num[l]);//能量
			b[l]-=cnt;
			sum-=energy;
			now-=cnt;
			if (b[l]==0)
			{
				l++;
			}
		}
		//cout<<sum<<' '<<now<<'\n';
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
} 
