#include<bits/stdc++.h>
using namespace std;
long long c,T,n,x[2000010],t[2000010],num,sum,ans;
long long d;
bool fl;
void dfs(int pos,int t,long long cnt)
{
	if(pos==t)
	{
		if(cnt==num)
			sum++;
		if(sum>2)
			fl=1;
		return ;
	}
	if(fl==1)	return ;
	if(cnt>=num)  return ;
	for(int i=pos+1;i<=t;i++)
	{
		if(x[i]-x[pos]<=d)
			dfs(i,t,cnt+1);
		else
			break;
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i]; 
		for(int i=1;i<=n;i++)
		{
			int l=i;
			t[l]=0;
			while(l<n)
			{
				int r=upper_bound(x+l,x+n+1,x[l]+d)-(x+1);
				if(r<=l)
				{
					l++;
					continue;
				}
				for(int k=l+1;k<=r;k++)
					t[k]=t[l]+1;
				l=r;
			}			
			for(int j=i+1;j<=n;j++)
			{
				fl=0;
				num=t[j];
				if(num==0)	num=1;
				sum=0;
				dfs(i,j,0);
				if(sum==2&&fl==0)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	} 
	return 0; 
}
