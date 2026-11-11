#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],mx=1,b[500001];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		int temp=m,cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			if(temp>=(b[i]-b[j]))
			{
				cnt++;
				b[j]=b[i];
				temp-=(b[i]-b[j]);
			}
		}
		if(cnt>=mx)
		{
			mx=cnt;
		}
	}
	
	cout<<mx;
	return 0;
}
