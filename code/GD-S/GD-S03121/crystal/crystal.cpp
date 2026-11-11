#include<bits/stdc++.h>
using namespace std;
long long a[500005];
vector<long long> v[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			v[i].push_back(max(a[i],a[j])-min(a[i],a[j]));
		}
	}
	long long MAX=0;
	for(long long i=0;i<n;i++)
	{
		long long ans=0;
		long long cnt=0;
		sort(v[i].begin(),v[i].end());
		for(long long j=0;j<v[i].size();j++)
		{
			ans+=v[i][j];
			cnt++;
			if(ans>m)
			{
				cnt--;
				MAX=max(MAX,cnt);
				break;
			}
		}	
	} 

	cout<<MAX;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
