#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500005],b[500005],maxn,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{ 
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		long long L=1,R=i,mid=0;
		while(L+1<R)
		{
			mid=(L+R)/2;
			if((i-mid)*a[i]-b[i-1]+b[mid-1]>=m){L=mid+1;}
			else {R=mid;}
		}
		maxn=max(maxn,i-L+1);
	}
	cout<<maxn;
	
	return 0;
} 
