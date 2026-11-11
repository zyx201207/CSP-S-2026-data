#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[2000005];
string z;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	long long x;
	while(l<r)
	{
		if(a[r]<=0) r--;
		if(a[l]<=0) l++;
		if(s[l]!=s[r])
		{
			
			sum+=min(a[l],a[r]);
			x=a[l];
			a[l]-=min(a[r],a[l]);
			a[r]-=min(x,a[r]);
		} 

		else
		{
			x=a[l];
			a[l]-=min(a[r],a[l]);
			a[r]-=min(x,a[r]);
		}
	}
	cout<<sum;
	return 0;
}

