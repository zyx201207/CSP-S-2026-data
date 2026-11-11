#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long s[N];
int main()
{
	int n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char x;
		cin>>x;
		s[i]=x-'a'+1;
	}
	long long ans;
	int l=1,r=n;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[r]==a[l])
			{
				
				r--;
				l++;
			}
			else 
			{
				
				a[l]-=a[r];
				r--;
			}
		}
		if(s[l]!=s[r]) 
		{
			if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
