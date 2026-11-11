#include<iostream>
#include<vector>
using namespace std;
int ans=0,a[200001];
int n,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<4)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==2)
			{
				ans=2;
				break;
			}
			if(a[i]==3) ans=3;
		}
		if(ans==0) cout<<1;
		else cout<<ans;
	}
	else if(k==n)
	{
		for(int i=0;i<n;i++) ans=ans&a[i];
	}
	else
	{
		for(int i=0;i<n;i++) ans=max(ans,a[i]);
	}
	cout<<ans;
}
