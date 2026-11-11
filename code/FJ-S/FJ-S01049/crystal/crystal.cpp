#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
long long n,m,a[500100],ans=0;

long long check(int x)
{
	long long s=m,cnt=1;
	
	for(int i=x-1;i>=1;i--)
	{
		if(s>=(a[x]-a[i]))
		{
			s-=(a[x]-a[i]);
			cnt++;
		}
		else
			break;
	}
	return cnt;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		 cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,check(i));
	}
	cout<<ans<<endl;
	/*long long l=1,r=n;
	while(l<r)
	{
		long long mid=l+(r-l)/2;
		long long mid1=l+(mid-l)/2,mid2=mid+(r-mid)/2;
		long long a=check(mid1),b=check(mid2);
		cout<<mid1<<" "<<mid2<<endl;
		if(a>b)
	}
	cout<<check(l)<<endl;*/
	return 0;
}

