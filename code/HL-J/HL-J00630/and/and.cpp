#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200001];
ll mx=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mx=max(mx,(a[i]&a[j]));
			}
		}
	}
	cout<<mx;
	return 0;
}
