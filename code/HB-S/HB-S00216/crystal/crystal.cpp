#include<bits/stdc++.h>
using namespace std;
int n,m,s=0,t,k=1,ans=0;
int a[500005],b[500005]={0};
long long sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	s=sum/n;
	for(int i=1;i<=n;i++)
	{
		t=a[i]-s;
		if(t<0)
		{
			b[k]=t;
			k+=1;
		}
		if(t==0)
		{
			ans+=1;
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j]<b[j+1])
			{
				int c;
				c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
		}
	}
	while(1>0)
	{
		int minn=1;
		int cnt=0-b[minn];
		if(m-cnt>=0)
		{
			m-=cnt;
			ans+=1;
			minn+=1;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
