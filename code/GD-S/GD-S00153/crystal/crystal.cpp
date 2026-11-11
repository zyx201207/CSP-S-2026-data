#include<bits/stdc++.h>
using namespace std;
#define int long long // <------------------------
int n,m;
int a[500001];
int sum[500001];
int ans=1;
int hs(int i)
{
	int l=0,r=i-1;
	int ret=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int q=sum[i]-sum[mid]-(a[i]-a[mid])*mid;
		if(q<=m)
		{
			ret=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ret;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<'\n';
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		//cout<<sum[i]<<endl;
	}
	for(int i=2;i<=n;i++)
	{
		/*if(sum[i]<=m) 
		{
			ans=max(i,ans); continue;
		}*/
		int q=hs(i);
		if(q!=-1) ans=max(ans,i-q);
	}
	cout<<ans;
	return 0;
}
/*
sum[i]+(a[j]-a[i])*i

5 5
1 2 4 8 9

0
1
3+2=5
7+6+4=17
8+7+5+1=21

5 8
-3-1 2 2 7





*/
