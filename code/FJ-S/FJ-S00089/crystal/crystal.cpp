#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,t=0,c=0;
	cin >> n>>m;
	vector<long long> a(n),h(n);
	fill(h.begin(),h.end(),1);
	for(long long i=0;i<n;i++)
	{
		scanf("&%e",&a[i]);
	}
	for(long long i=0;i<n;i++)
	{
		t=0;
		for(long long j=0;j<n;j++)
		{
			if(i!=j)
			{
				c=abs(a[i]-a[j]);
				if(t+c<=m)
				{
					t+=c;
					h[i]++; 
				}
				
			}
			else
			{
				continue;
			}
		}
	}
	sort(h.begin(),h.end());
	cout <<h[n-1];
	return 0;
}
