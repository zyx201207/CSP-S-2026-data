#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,a[500005],maxx=INT_MIN;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
		long long maxxn=1,mtp=m;
		for(int j=i-1;j>=1;j--)
		{
			if(mtp>=a[i]-a[j])//¹» 
			{
				mtp-=a[i]-a[j];
				maxxn++;
			}
		}
		maxx=max(maxx,maxxn);
	}
	cout<<maxx;
	return 0;	
} 
