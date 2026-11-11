#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,b[32],s[200005],ans;
bool a[200005][32];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<200001;i++)s[i]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll p,j=1;
		cin>>p;
		while(p)
		{
			a[i][j]=p&1;
			b[j]+=ll(1ll*a[i][j]);
			p/=2;
			j++;
		}
	}
	for(int i=30;i>0;i--)
	{
		ll pow=1;
		for(int j=1;j<i;j++)pow*=2;
		if(b[i]<m)continue;
		ll k=0;
		for(int j=1;j<=n;j++)
			if((s[j]==1)&&a[j][i])k++;
		if(k>=m)
		{
			for(int j=1;j<=n;j++)
				if(a[j][i]==0)s[j]=0;
			ans+=pow;
		}
	} 
	cout<<ans;
	return 0;
} 
