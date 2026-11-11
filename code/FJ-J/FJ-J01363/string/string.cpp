#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
ll n,a[N],ans;char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for (int i=1,j=n;i<j;)
	{
		if (a[i]>a[j])
		{
			a[i]-=a[j];
			if (c[i]!=c[j]) ans+=a[j];
			j--;
		}
		else if (a[i]<a[j])
		{
			a[j]-=a[i];
			if (c[i]!=c[j]) ans+=a[i];
			i++;
		}
		else
		{
			if (c[i]!=c[j]) ans+=a[i];
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}