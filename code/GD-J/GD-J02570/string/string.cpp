#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5]={0};
	char c[n+5];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mina=min(a[l],a[r]);
		int maxa=max(a[l],a[r]);
		if(c[l]!=c[r])
		{
			ans+=mina;
		}
		a[l]-=mina;
		a[r]-=mina;
		if(a[l]<=0)
		{
			l++;
		}
		if(a[r]<=0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
