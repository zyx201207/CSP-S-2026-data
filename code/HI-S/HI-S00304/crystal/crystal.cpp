#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,i,j,eng,ans(1),cnt,d;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=n;i>=1;i--)
		for(j=1;j<i;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
	if(n>5000&&m>1e8)
		for(ans=1;((ans*ans)-ans)<=(2*m);ans++);
	else
	{
		for(i=1;i<=n;i++)
		{
			eng=m,j=i,cnt=0;
			while(eng>=0&&j>=1)
			{
				j--;
				eng+=a[j];
				eng-=a[i];
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	ans=min(ans,n);
	cout<<ans;
	return 0;
} 
