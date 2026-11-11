#include<iostream>
#include<algorithm>
#include<stdio.h>
#define ll long long
using namespace std;
const int N=5e5+42;
ll a[N],ans,n,m,db;;
bool flag=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	db=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(db!=a[i]-a[i-1])flag=0;
	}
	if(flag)
	{
		ll tmp=m,cnt=1;
		while(tmp-a[n]+a[n-cnt]>=0&&cnt<n)
		{
			tmp=tmp-a[n]+a[n-cnt];
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		ll tmp=m,cnt=1;
		while(tmp-a[i]+a[i-cnt]>=0&&i-cnt>0)
		{
			tmp=tmp-a[i]+a[i-cnt];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
} 
