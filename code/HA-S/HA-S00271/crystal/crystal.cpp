#include<bits/stdc++.h>
using namespace std;
int n;
long long m; 
int a[100010];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];

	}
	sort(a+1,a+1+n);
	int mid=n/2+1;
	for(int i=mid;i>=1;i--)
	{
		int k=a[i]-a[i-1];
		if(m>0)
		{
			m-=k;
			a[i-1]+=k;
			cout<<a[i]<<" "<<k<<" "<<m<<" "<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[mid]==a[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
