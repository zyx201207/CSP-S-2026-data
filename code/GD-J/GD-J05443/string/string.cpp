#include<bits/stdc++.h>
using namespace std;
char a[200005],c[200005];
int b[200005],n,t,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>b[i]>>c[i];
		int o=n;
		n+=b[i];
		for(int j=o;j<=n;j++)
		{
			a[j]=c[i];
		}
	}
	int mid=(1+n)/2,i=1,j=n;
	while(i<=j)
	{
		if(a[i]!=a[j])
		{
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
} 
