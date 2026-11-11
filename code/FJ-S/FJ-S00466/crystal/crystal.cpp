#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long qz[500005];
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1,ans=1;
	for(r=2;r<=n;r++)
	{
		m-=(r-l)*(a[r]-a[r-1]);
		while(m<0)
		{
			m+=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;

	return 0;
}

