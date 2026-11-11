#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,t,a[N],ans,cnt[N],l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)	cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
	l=1;
	r=1;
	while(r<=n)
	{
		t=cnt[r]-cnt[l]-(l-1)*(a[r]-a[l]);
		if(t>m)	l++;
		if(t<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
}
