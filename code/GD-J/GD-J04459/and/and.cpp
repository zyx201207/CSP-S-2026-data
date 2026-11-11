#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	int idx = 0;
	for(i=m;i<n;i++)
	{
		if(a[i] == a[m-1])
			swap(a[i],a[idx++]);
		else break;
	}
	ll ans = a[0];
	for(i=1;i<m;i++) ans &= a[i];
	if(ans == 0)
		for(i=0;i<n-1;i++)
			if(a[i]%2==1 && a[i+1]==a[i]-1)
			{
				ans = a[i+1];
				break;
			}
	cout<<ans;
	return 0;
}
