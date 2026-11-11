#include<bits/stdc++.h>
using namespace std;
long long l,r=1,sum,cnt=0,mid,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	vector<long long>a(n+1,0);
	vector<char>c(n+1,0);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	vector<long long>d(sum+1,0);
	int start=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=start;j<=a[i]+start;++j)
		{
			d[j]=c[i];
		}
		start+=a[i];
	}
	for(int i=1;i<=sum/2;++i)
	{
		if(c[i]!=c[sum-i+1])
		{
			cnt++;
		}
	}
	cout<<cnt;
}
