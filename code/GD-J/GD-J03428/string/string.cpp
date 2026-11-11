#include<bits/stdc++.h>
using namespace std;
int n,a[222222];
char c[222222];
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];r--;
		}
		else if(a[l]==a[r])
		{
			if(c[l]!=c[r])ans+=a[r]; 
			l++;r--;
		}
		else 
		{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];l++;
		}
	}
	cout<<ans;
}

