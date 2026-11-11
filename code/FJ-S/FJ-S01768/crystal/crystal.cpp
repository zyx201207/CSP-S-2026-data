#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5010],w[5010][5010],s,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]) swap(a[i],a[j]);
	for(int i=1;i<=n-1;i++)
	{
		s=a[i];
		for(int j=i+1;j<=n;j++)
		{
			w[i][j]=a[j]*(j-i)-s;
			s+=a[j];
		}
	}
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(m>=w[i][j])
				if(maxn<j-i+1) maxn=j-i+1;
	cout<<maxn;
	return 0;
}