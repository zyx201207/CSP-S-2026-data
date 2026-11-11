#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	long long c1=a[1],c2=a[n],t1=1,t2=n;
	long long ans=0;
	while(t1<t2)
	{
		if(c[t1]!=c[t2])
		{
			ans++;
		}
		c1--,c2--;
		if(c1==0)
		{
			t1++;
			c1=a[t1];
		}
		if(c2==0)
		{
			t2--;
			c2=a[t2];
		}
	}
	cout<<ans;
}
