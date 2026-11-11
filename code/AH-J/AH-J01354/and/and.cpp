#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005][32],c[200005],t[200005],maxn=0;
int check(int x)
{
	int sum=1;
	for(int i=1;i<=x;i++) sum*=2;
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],j=1;
		while(x)
		{
			if(x%2==1) c[j]++;
			b[i][j]=x%2;
			j++;
			x/=2;
		}
		maxn=max(maxn,j-1);
	}
	int flag=1,ans=0;
	for(int i=1;i<=n;i++) t[i]=1;
	for(int i=maxn;i>=1;i--)
	{
		if(c[i]>=m&&flag==1)
		{
			flag=0;
			for(int j=1;j<=n;j++)
				if(b[j][i]==0) t[j]=0;
			ans+=check(i-1);
		}
		else if(flag==0)
		{
			int s=0;
			for(int j=1;j<=n;j++)
				if(b[j][i]==1&&t[j]==1) s++;
			if(s<m) continue;
			else
			{
				for(int j=1;j<=n;j++)
				if(b[j][i]==0) t[j]=0;
				ans+=check(i-1);
			}
		}
	}
	cout<<ans;
	return 0;
}
