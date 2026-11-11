#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	int ans=1,tmp=1;
	for(int i=1;i<n;i++)
	{
		tmp=1;
		for(int j=i;j<n;j++)
		{
			if(m<b[j])break;
			m-=b[i];
			tmp++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
 } 
