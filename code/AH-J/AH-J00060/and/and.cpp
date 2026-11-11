#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool flag[N];
int bit[N][35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int a,i=1;i<=n;i++)
	{
		cin>>a;
		int x=a;
		int cnt=0;
		while(x)
		{
			bit[i][++cnt]=x%2;
			x>>=1;
		}
	}
	for(int k=31;k>=1;k--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==1)continue;
			if(bit[i][k]==1)
				cnt++;
		}
		if(cnt<m)continue;
		for(int i=1;i<=n;i++)
			if(bit[i][k]==0)
				flag[i]=1;
		bit[0][k]=1;
	}
	int ans=0;
	for(int k=1;k<=31;k++)
		ans+=(bit[0][k]<<k-1);
	cout<<ans;
	return 0;
} 
