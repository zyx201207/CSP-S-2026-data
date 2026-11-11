#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long a[n],maxn=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=m;i--)
	{
		long long ij=a[i];
		for(int j=i-1;j>(i-m);j--)
		{
			ij=ij&a[j];
		}
		if(ij>maxn) maxn=ij;
	}
	cout<<maxn;
	return 0;
}

