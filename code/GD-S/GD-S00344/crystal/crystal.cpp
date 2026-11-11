#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		while(a[i]*(i-l+1)-sum>m)
		{
			sum-=a[l++];
		}
		ans=max(ans,(long long)i-l+1);
	}
	cout<<ans;
}
