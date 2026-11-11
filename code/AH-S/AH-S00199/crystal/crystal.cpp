#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
const int INF=1e12+10;
int n,m,mn=INF,mx=-INF;
int a[N]; 
bool f1=1,f2=1;
bool check(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x) ans+=x-a[i];
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) 
		{
			f1=0;
		}
	}
	int gc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1]!=gc)) f2=0;
	}
	sort(a+1,a+n+1);
//	cout<<f1<<' '<<f2<<'\n';
	if(f1)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if(i*(i-1)/2<=m)
				ans=i;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(f2)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if((a[i]-a[1]+a[i]-a[i-1])*(i-1)/2<=m)
				ans=i;
		}
		cout<<ans<<'\n';
		return 0;
	}
	int l=a[1],r=INF,h=0;//¸ß¶È 
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) {
			l=mid;
		}
		else r=mid-1;
	}
	h=r;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=h) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
