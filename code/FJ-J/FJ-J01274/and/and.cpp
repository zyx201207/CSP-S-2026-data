#include<bits/stdc++.h>
using namespace std;

long a[200005];
long af[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans = 0;
	long long n,m;
	cin>>n>>m;
	for(long long i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	
	
	sort(a,a+n);
	
	long long t = 0;
	for(long long i = n-1;i >= 0;i--)
	{
		af[t] = a[i];
		t++;
	}
	
	

	

	int o = 0;
	
	while(ans == 0)
	{
		ans = af[o];
		for(int i = o+1;i < o+m;i++)
		{
			ans = ans&af[i]; 
		}
		o++;
		if(ans != 0) break;
	
	}
	
	cout<<ans;
	return 0;
	
}
