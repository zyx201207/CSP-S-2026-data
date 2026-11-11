#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	long long now=a[0],ret=0,cnt=1;
	
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])cnt++;
		else
		{
			ret=max(ret,cnt);
			cnt=1;
		}
	}
	ret=max(ret,cnt);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]<now)m-=now-a[i];
		else
		{
			m-=(i-1)*(a[i]-now);
			now=a[i];
		}
		if(m<0)
		{
			ret=max(ret,(long long)i);
			break;
		}
	}
	cout<<ret;
	return 0;
} 
