#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200005]; 
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	unsigned long long cnt=0;
	int i=1,j=n;
	while(i!=j)
	{
		long long ans=min(a[i],a[j]);
		a[i]-=ans,a[j]-=ans;
		if(c[i]!=c[j]) cnt+=ans;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<cnt;
	return 0;	
}
