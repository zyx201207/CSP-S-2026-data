#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool b[200005];
void s(int x,int z)
{
	if(z==m)
	{
		int sum=0,cnt=0,k=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1&&sum==0)
			{
				cnt=a[i];
				k=i;
				sum++;
			}
		}
		for(int i=k+1;i<=n;i++)
		{
			if(b[i]==1)
			{
				cnt&=a[i];
			}
		}
		ans=max(ans,cnt);
		return;
	}
	if(x==n+1)
	{
		return;
	}
	b[x]=1;
	s(x+1,z+1);
	b[x]=0;
	s(x+1,z);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	s(1,0);
	cout<<ans;
	return 0;
} 
