#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long a[1000000];
long long ans=0;
long long k=0,jishu=0,qushe=0;
long long b[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		ans=0;
		for(int j=i-1;j>=0;j--)
		{
			ans+=a[i];
			ans-=a[j];
			if(ans<=m)
			{
				b[i]=b[j]=1;
			}
			else
			{
				break;
			 } 
		}
		for(int f=0;f<n;f++)
		{
			if(b[f]==1)
			{
				jishu+=1;
			 }
			b[f]=0; 
		}
		if(jishu>qushe)
		{
			qushe=jishu;
		}
		jishu=0;
	}
	cout<<qushe;
	return 0;
 } 
