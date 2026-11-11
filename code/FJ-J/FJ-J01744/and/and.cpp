#include<bits/stdc++.h>
using namespace std;
int v[2321322],f[3422333],g[324233],h[4324243];
int n,m,a[3242423],b[432432],ans=-1,sum,r;
int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>0;j/=2)
		{
			int t=1;
			v[t]=j%2;
			
			t++;
			r=t;
		}
		for(int j=a[i];j>0;j/=2)
		{
			int t=1;
			h[t]=v[t];
			t++;
		}
		if(i==1) {
			for(int j=a[i];j>0;j/=2)
			{
				int t=1;
				f[t]=h[t];
				t++;
			}
		}
		else
		{
			for(int j=r;j>=1;j--)
			{
				if(f[j]==h[j]) g[j]=1;
				else g[j]=0;
			}
			for(int j=1;j<=r;j++)
			{
				int e=1;
				sum+=g[j]*e;
				e*=2;
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans*2;
	return 0;
}
