#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<ll> a(n+1);
	vector<char> c(n+1);
	ll k=0;
	for(int i=1;i<=n;i++)
	{
		int x;char y;
		cin>>x>>y;
		if(c[i-1]==y)
		{
			a[i-1]+=x;
		}
		else
		{
			k++;
			a[i]=x;c[i]=y;
		}
	}
	ll ans=0;
	for(int i=1,j=n;i<j;)
	{
		if(c[i]==c[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
		else
		{
			ans+=min(a[i],a[j]);
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
