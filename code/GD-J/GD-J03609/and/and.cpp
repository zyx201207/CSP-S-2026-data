#include<bits/stdc++.h>
using namespace std;
long long n,p,m,a,b,c,f[200005],g[200005],t[200005][35],cnt,cnt1,ans,op[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>g[i];
	for(int i=1;i<=n;i++)
	{
		a=g[i];
		cnt=0;
		while(a)
		{
			t[i][++cnt]=a%2;
			a/=2;
		}
		cnt1=max(cnt1,cnt);
	}
	op[0]=1;
	for(int i=1;i<=30;i++)
	{
		op[i]=op[i-1]*2;
	}
	for(int i=cnt1;i>=1;i--)
	{
		long long sum=0;
		for(int j=1;j<=n;j++)
		{
			if(t[j][i]&&f[j]==0)
			{
				sum++;
			}
		 } 
		 if(sum>=m)
		 {
		 	ans+=op[i-1];
		 	for(int j=1;j<=n;j++)
		 	{
		 		if(t[j][i]==0)
		 		f[j]=1;
			 }
		 }
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	cout<<ans;
	return 0;
}
