#include<bits/stdc++.h>
using namespace std;
long long a[200005];
//long long tmp[200005];
long long p[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int cnt[35]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//tmp[i]=a[i];
	}
	p[0]=1;
	for(int i=1;i<=32;i++)
	{
		p[i]=p[i-1]*2;
	}
	for(int i=30;i>=0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=p[i+1])
			{
				a[j]-=p[i+1];
			}
		}
		for(int j=1;j<=n;j++)
		{

			if(a[i]!=-1&&(a[j]>=p[i]))
			{
				cnt[i]++;
			}
		}
		//cout<<'C'<<cnt[i]<<' '<<m<<endl;
		if(cnt[i]>=m)
		{
			//cout<<'J';
			for(int j=1;j<=n;j++)
			{	
				if(a[j]<p[i])
				{
					//cout<<'S'<<tmp[j];
					a[j]=-1;
				}
			}
			//cout<<endl;
		}
	}
	long long ans=0;
	//for(int i=30;i>=0;i--)cout<<cnt[i];
	//cout<<endl;
	for(int i=30;i>=0;i--)
	{
		ans*=2;
		if(cnt[i]>=m)
		{
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}