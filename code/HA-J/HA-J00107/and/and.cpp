#include<bits/stdc++.h>
using namespace std;
//define int long long
//define int __int128
const int N=1e6,A=1e9;
int n,m,a[N],p[31],sum,ans;
signed main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//freopen(".in","w",stdout);
	//freopen(".out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++)p[i]=(p[i-1]<<1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>-1;i--)
	{
		sum=0;
		for(int j=1;j<=n;j++)
			sum+=((a[j]&p[i])!=0?1:0);
		if(sum>=m)
		{
			ans+=p[i];
			for(int j=1;j<=n;j++)
				if((a[j]&p[i])==0)a[j]=0;
		}
	}
	cout<<ans;
	return 0;
}

