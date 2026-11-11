#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],s[N];
bool check(int mid)
{
	long long minn=LLONG_MAX;
	for(int i=mid;i<=n;i++) 
	{
		long long k=(mid-1)*a[i]-s[i-1]+s[i-mid];
		minn=min(minn,k);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
