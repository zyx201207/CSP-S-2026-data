#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005],ans=0;
int main()
{
#ifndef zhengyi
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
//	freopen("E:\\csps-new\\down\\crystal\\crystal4.in","r",stdin);
	
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int j=1;j<=n;j++)
	{
	//	int si=m-(j-i)*a[j]+sum[j-1];
		ll i=0x3f3f3f3f3f3f3f3f,l=1,r=j;
		while(l<=r)
		{
			ll mid=l+r>>1;
		//	cout<<j<<" "<<mid<<" "<<(j-mid)*a[j]-sum[j-1]+sum[mid-1]<<" ";
			if((j-mid)*a[j]-sum[j-1]+sum[mid-1]<=m)r=mid-1,i=mid;
			else l=mid+1;
		//	cout<<endl;
		}
	//	if(i<0)exit(114514);
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

//*/
