#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n;
	int ans=0;
	cin>>n>>m;
	vector<unsigned long long> diamond(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>diamond[i];
	}
	sort(diamond.begin(),diamond.end());
	if(n>16)
	{
		unsigned long long a=0;
		int i=1;
		for(;a<=m;i++)
		{
			unsigned long long b=a;
			a+=(diamond[i]-diamond[i-1])*i;
			if(a<=b||a-b!=(diamond[i]-diamond[i-1])*i)break;
		}
		cout<<i-1;
		return 0;
	}
	vector<unsigned long long>need(n,0);
	vector<unsigned long long>qzh(n,diamond[0]);
	for(int i=1;i<n;i++)
	{
		need[i]=need[i-1]+(diamond[i]-diamond[i-1])*i;
		qzh[i]=diamond[i]+qzh[i-1];
	}
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j>=1&&need[i]-j*diamond[i]+qzh[j-1]<m)j--;
		ans=max(i-j+1,ans);
	}
	cout<<ans;
	return 0;
} 
