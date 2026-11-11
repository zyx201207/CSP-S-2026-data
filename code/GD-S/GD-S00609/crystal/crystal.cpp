#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t1=0,t2,t;
	bool z1=1,z2=1;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	t2=a[2]-a[1];
	if(t2!=0)	z1=0;
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		t=a[i]-a[i-1];
		if(t2!=t||!z2)	z2=0;
		if(t1!=0||!z2)	z1=0;
	}
	if(z1){
		cout<<n<<endl;
		return 0;
	}
	if(z2){
		cout<<m/t2<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=0,s,ss,mid;
	for(int j=a[1];j<=a[n];j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=j&&a[i+1]>j)
			{
				mid=i;
				break;
			}
		}
		long long s=0,ss=0;
		for(int i=mid;i>=1;i--)
		{
			long long k=j-a[i];
			if(s+k>m)
			{
				break;
			}
			else
			{
				s+=k;
				ss++;
			}
		}
		ans=max(ans,ss);
	}
	cout<<ans<<endl;
	return 0;
}
