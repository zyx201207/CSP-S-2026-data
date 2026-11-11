#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],ans=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	ll cnt=0,sy=m,j=n;
	for(j;j>=1;j--)
	{
		if(sy-(a[n]-a[j])>=0)
		 cnt++,sy-=(a[n]-a[j]);
		else
			break;
	}
	if(cnt==n)
	{
		cout<<n;
		return 0;
	}
//	cout<<cnt<<endl;
	ans=max(ans,cnt);
	for(int i=n-1;i>=1;i--)
	{
		cnt--;
		sy+=(a[i+1]-a[i])*cnt;
//		cout<<"m:"<<sy<<endl;
		for(j;j>=1;j--)
		{
//			cout<<j<<"][";
			if(sy-(a[i]-a[j])>=0)
			 cnt++,sy-=(a[i]-a[j]);
			else
				break;
		}
//		cout<<endl;
//		cout<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
