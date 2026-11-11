#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
long long m,c[500010];
bool check(int k)
{
	long long s=0;
	for(int i=1;i<k;i++)s+=a[k]-a[i];
	if(s<=m)return 1;
	for(int i=k+1;i<=n;i++)
	{
		s=s+c[i]*k-a[i-1]+a[i-k];
		if(s<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	int z=1,y=n,mid;
	while(z<y)
	{
		mid=(z+y+1)/2;
		if(check(mid)==1)z=mid;
		else y=mid-1;
	}
	mid=(z+y+1)/2;
	if(mid<2)cout<<0;
	else cout<<mid;
	return 0;
 } 
