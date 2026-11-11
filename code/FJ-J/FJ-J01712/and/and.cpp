#include<bits/stdc++.h>
using namespace std;
long long a[200005][35],rw[200005],nz[200005],len1[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++)
	{
		long long z;
		cin>>z;
		nz[i]=z;
		long long len=0,z1=z;
		while(z1)
		{
			z1/=2;
			len++;
		}
		len1[i]=len;
		maxx=max(maxx,len);
		rw[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;nz[i]>0;j++)
		{
			a[i][maxx-j+1]=nz[i]%2;
			nz[i]/=2;
		}
	}
	string ans="";
	for(int i=1;i<=maxx;i++)
	{
		int gs=0;
		for(int j=1;j<=n;j++){
			if(rw[j])
			{
				gs+=(a[j][i]==1);
			}
		}
		if(gs<m)
		{
			ans+="0";
		}
		else
		{
			ans+="1";
			for(int j=1;j<=n;j++){
				if(rw[j]&&a[j][i]==0)
				{
					rw[j]=0;
				}
			}
		}
	}
	long long pow=1,ans1=0;
	for(int i=ans.length()-1;i>=0;i--)
	{
		ans1+=(ans[i]-'0')*pow;
		pow*=2;
	}
	cout<<ans1;
	return 0;
} 
