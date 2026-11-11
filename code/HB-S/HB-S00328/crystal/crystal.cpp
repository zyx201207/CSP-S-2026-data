#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int mx=-1e9,mi=1e9;
int ans;
bool f=1,flag=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int d1,d2,d;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)
		{
			d1=a[i];
		}if(i==2)
		{
			d2=a[i];
			d=d2-d1;
		}
		if(a[i]!=i) f=0;
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
		if(i>2)
		{
			if(a[i]-a[i-1]!=d)
			{
				flag=0;
			}
		}
	}
	if(f)
	{
		int sum=0;
		while(sum<=m)
		{
			ans++;
			sum+=sum+1;
		}
		cout<<ans;
		return 0;
	}if(flag&&n>2){
		int sum=0;
		while(sum<=m)
		{
			ans++;
			sum+=sum+d;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=mi;i<=mx;i++){
		int cnt=0;
		int t=m;
		for(int j=n;j>=1;j--){
			if(a[j]>i) continue;
			if(t<i-a[j]) break;
			cnt++;
			t-=(i-a[j]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
