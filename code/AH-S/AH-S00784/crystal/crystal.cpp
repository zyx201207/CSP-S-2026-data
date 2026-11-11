#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	for (int i=3;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+n+1);
	long long d=a[2]-a[1];
	bool ok=1;
	for (int i=3;i<=n;i++)
		if (a[i]-a[i-1]!=d) ok=0;
	if (ok==0)
	{
		for (int i=1;i<=n;i++)
			b[i]=b[i-1]+a[i];
		for (int i=n;i>=2;i--)	 //枚举个数 
		{
			for (int j=1;j<n-i+1;j++)  //枚举起点
				if (a[j+i-1]*i-b[j+i-1]+b[j-1]<=m)
				{
					cout<<i;
					return 0;
				}
		}
	}
	else
	{
		long long x=m/d,s=0,i;
		for (i=1;s+i<=x;i++)
			s+=i;
		cout<<i;
	}
	return 0;
}
