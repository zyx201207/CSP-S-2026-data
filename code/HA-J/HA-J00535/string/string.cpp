#include<bits/stdc++.h>
using namespace std;
long long a[200100],n,m,k,sum,c;
char b[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	k=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(k<m)
	{
		if(b[k]!=b[m])sum+=min(a[k],a[m]);
		c=min(a[k],a[m]);
		a[k]-=c;
		a[m]-=c;
		if(a[m]==0)m--;
		if(a[k]==0)k++;
	}
	cout<<sum;
	return 0;
}
