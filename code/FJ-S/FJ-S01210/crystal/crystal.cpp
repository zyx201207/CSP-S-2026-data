#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],b[500005],o=0, l,r,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i-1]=a[i]-a[i-1];
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<endl<<a[i]<<" "<<b[i];
	}*/
	r=1,l=1;
	while(o<=m)
	{
		if(o+b[r]<=m)
		{
			o+=b[r];
			r++;
			ans++;
		}
		else
		{
			break;
		}
	}
	cout<<ans+1;
	return 0;
}

