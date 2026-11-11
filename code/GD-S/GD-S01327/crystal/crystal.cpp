#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],ans;
bool check(int x)
{
	long long s=0,v=0;
	for(int i=x-1;i>=1;i++)
	{
		if(s+a[x]-a[i]<=m)
		{
			v++;
			s+=a[x]-a[i];
		}
		else
			break;
	}
	if(v>=ans)
	{
		ans=v;
		return 1;
	}
	return 0;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
 } 
