#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool comp(int a,int b)
{
	int c=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
	for(int i=30;i>=0;i--)
	{
		if((a&c)>(b&c))return 1;
		if((a&c)<(b&c))return 0;
		c>>=1;
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=2147483647;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,comp);
//	cout<<a[0]<<' '<<a[1]<<' '<<a[2];
	for(int i=0;i<m;i++)ans&=a[i];
//	if(m==2)
//	{
//		if((a[0]&a[2])>ans)ans=(a[0]&a[2]);
//		if((a[1]&a[2])>ans)ans=(a[1]&a[2]);
//	}
	cout<<ans;
}
