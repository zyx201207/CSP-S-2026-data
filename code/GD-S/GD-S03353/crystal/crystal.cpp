#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N];
long long he[N];
long long m;
long long ans;
bool judge(int l,int r)
{
	int len=r-l;
	long long need=len*a[r]-(he[r-1]-he[l-1]);
//	cout<<l<<" "<<r<<" "<<need<<endl;
	if(need<=m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int getpos(int r)
{
//	cout<<r<<endl;
	int l=1;
	int rr=r;
	int tmppos=0;
	while(l<=rr)
	{
		int mid=(l+rr)>>1;
		if(judge(mid,r)==true)
		{
			tmppos=mid;
			rr=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return tmppos;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	he[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		he[i]=he[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<he[i]<<endl;
//	}
	for(int i=2;i<=n;i++)
	{
		int pos=getpos(i);
		ans=max(ans,1ll*(i-pos+1));
	}
	cout<<ans<<endl;
	return 0;
}
