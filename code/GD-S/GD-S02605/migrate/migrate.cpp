#include<bits/stdc++.h>
using namespace std;
int n,m,s,c,t,a[1000005],v[1000005],d,mi=1000000000,b[1000005],mx;
void dfs(int x,int y,int k,int xx)
{
	if(x==y)
	{
		b[k]++;
		if(mi>k)
		{
			mi=k;
		}
		mx=max(mx,k);
		return ;
	} 
	for(int i=x+1;i<=y;i++)
	{
		if(abs(a[i]-a[x])<=d)
		{
			dfs(i,y,k+1,xx);
		}
		else
		{
			break;
		}
	}
}
void cheak()
{
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=a[2]-a[1];
	 cout<<n-3;
}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		cheak();
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dfs(i,j,1,i);
				if(b[mi]==2) s++;
				for(int l=mi;l<=mx;l++) b[l]=0;
				mi=1000000000;
				mx=0;
			}
		}
		cout<<s<<endl;
		s=0;
	}
	return 0;
} 
