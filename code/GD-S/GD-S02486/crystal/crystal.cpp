#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N=5*1e5+5;

int n,m;
int a[N],win[N];

bool issq()
{
	int las=0,now=a[1];
	for(int i=2; i<=n; i++)
	{
		las=now;
		now=a[i]-a[i-1];
		if(las!=now) return false;
	}
	return true;
}

bool check(int str,int las)
{
	int tem=m;
	for(int i=str; i<las; i++) tem-=(a[las]-a[i]);
	if(tem>=0) return true;
	return false;
}

int isr(int str)
{
	int l=str,r=n;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(str,mid)) l=mid+1;
		else r=mid-1;
	}
	return l-str;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(issq()) {
		cout<<isr(1)<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1; i<=n; i++) ans=max(ans,isr(i));
	cout<<ans<<endl;
	return 0;
}

/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
