#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],b[500005];

long long getcha(int l, int r)
{
	return b[r]-b[l]-(long long)(l-1)*(a[r]-a[l]);
}

int erfen(int i)
{
	int l=i+1,r=n;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(getcha(i,mid) > m) r=mid-1;
		else l=mid+1;
	}
	return r;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{  
		cin>>a[i];
	}
	sort(a,a+n);
	
	for(int i=2;i<=n;i++)
	{
		b[i] = b[i-1] + (a[i]-a[i-1]) * (i-1);
	}
	
	int maxlen = -1;
	for(int i=1;i<=n;i++)
	{
		int j = erfen(i);
		if(maxlen < j-i+1) maxlen = j-i+1;
	}
	
	cout<<maxlen;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


