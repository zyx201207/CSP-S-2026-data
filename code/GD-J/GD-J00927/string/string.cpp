#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	int i=0,j=n;
	int k1=a[0],k2=a[n];
	char c1=c[0],c2=c[n];
	long long ans=0;
	while(i<j)
	{
		int l = min(k1,k2);
		if(c1!=c2)
		{
			ans+=l;
		}
		k1-=l;
		k2-=l;
		if(k1 == 0)
		{
			i++;
			k1 = a[i];
			c1 = c[i];
		}
		if(k2 == 0)
		{
			j--;
			k2 = a[j];
			c2 = c[j];
		}
	}
	cout<<ans;
	return 0;
} 
