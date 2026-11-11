#include<bits/stdc++.h>
using namespace std;
int c,n,t,d;
const int N=2e6+10;
int a[N];
int diff[N];
int	js[N];
int min_n;
void dfs(int r,int l,int step)
{
	if(r==l)
	{
		js[step]++;
		min_n=min(min_n,step);
		return;
	}
	if(r>l)
	{
		return;
	}
	for(int j=r+1;j<=l;j++)
	{
		if(a[j]-a[r]<=d)
		{
			dfs(j,l,step+1); 
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cnt=0;
	cin>>c>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n>>d;	
		for(int i=1;i<=n;i++)
		{
			
			cin>>a[i];
		}
		for(int l=1;l<=n;l++)
		{
			
			for(int r=l+1;r<=n;r++)
			{
				
				min_n=0x3f3f3f3f;
			
				dfs(l,r,0);
				if(min_n==0x3f3f3f3f)
				{
					min_n=0;
				}
				if(js[min_n]==2)
				{
					cnt++;
				}
				
				for(int s=1;s<=n;s++)
				{
					js[s]=0;
				}
			}
			
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
