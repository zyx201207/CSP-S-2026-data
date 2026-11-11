#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,k;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++)cin>>a[i]>>c[i];
	for(int i=0;i<n;i++)
	{
		k=n-1;
		if(a[i]==0)break;
		while(a[i]!=0)
		{
			if(a[k]==0)k--;
			if(c[i]!=c[k])cnt+=min(a[i],a[k]);
			if(a[i]<=a[k])a[k]-=a[i],a[i]=0;
			else a[i]-=a[k],a[k]=0; 	
		}	
	}	
	cout<<cnt;
	return 0;
}
