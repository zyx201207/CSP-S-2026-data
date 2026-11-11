#include<bits/stdc++.h>
using namespace std;
long long m,n;
const int N=500005;	
long long a[N];
long long qz[N] = {0};//Ç°×ººÍ 
int maxx = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		qz[i]=a[i]+qz[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//[i,j]
		{
			if((qz[j]-qz[i-1]+m)/a[j] >= j-i+1)
			{
				maxx=max(maxx,j-i+1);
			}
		}
	}
	cout<<maxx;
	return 0;
}
