#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200086],num,ans,maxx=-9178,used[200086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==m)
	{
		ans=1048575;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];ans=ans&a[i];
		}
		cout<<ans;return 0;
	}
	if(m==1)
	{
		ans=-10086;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];ans=max(ans,a[i]);
		}
		cout<<ans;return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=(1<<n);i++)
		{
			num=0;ans=1048575;
			memset(used,0,sizeof(used));
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)){num++;used[j+1]=1;}
			}
			if(num==m)
			{
				for(int j=1;j<=n;j++)
				{
					if(used[j])ans=ans&a[j];
				}
				maxx=max(maxx,ans);
			}
			
		}
		cout<<maxx;return 0;
	}
	else {
		cout<<0;return 0;
	}
	return 0;
}
