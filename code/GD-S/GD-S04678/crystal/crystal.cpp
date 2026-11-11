#include<bits/stdc++.h>
using namespace std;
long long a[500100];
long long n,m;
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)  cnt+=(a[x]-a[i]);
	if(cnt>m) return false;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);  
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	long long l=0,r=n+1;
	bool f=false;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
		if(l==r-1&&f) break;
		else f=1;
	}
	cout<<l;
	return 0;
 } 
