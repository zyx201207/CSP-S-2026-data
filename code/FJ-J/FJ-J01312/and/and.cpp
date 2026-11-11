#include<bits/stdc++.h>
using namespace std;
long long ans=-1;
int n,m;
int a[200001];
void fs(int i,int j,long long p)
{
	if(j==m)
	{
		ans=max(ans,p);
		return ;
	}
	if(i>n)
	{
		return ;
	}
	fs(i+1,j+1,p&a[i]);
	fs(i+1,j,p);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int b=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=30;i++)
	{
		b*=2;
	}
	fs(1,0,b-1);
	cout<<ans;
	return 0;
}
