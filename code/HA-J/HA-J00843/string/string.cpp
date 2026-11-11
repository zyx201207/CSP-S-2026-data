#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	int l=1,r=n;
	int sum=0,mid=0;
	for(int i=1;i<=n;i++)
	{
		mid++;
		if(sum>(cnt/2))
		{
			mid--;
			break;
		}
		sum+=a[i];
	}
	sum=0;
	while(l<=mid && r>=mid)
	{
		if(c[l]!=c[r])
		{
			if(sum>=0)
				ans+=a[r];
			if(sum<0)
				ans+=a[l];
			sum+=a[l]-a[r];
		}
		if(sum==0)
		{
			r--;
			l++;
		}
		if(sum>0)
			r--;
		if(sum<0)
			l++;
	}
	if(cnt%2==1 && ans!=0)
		ans--;
	cout<<ans;
	return 0;
}
