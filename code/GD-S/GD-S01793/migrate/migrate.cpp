#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
long long partA()
{
	long long l=a[2]-a[1];
	l=d/l;
	if(l<2||l*2>n) return 0;
	l*=2;
	return n-l+1;
}
long long part1()
{
	long long f[n+5][2],ans=0;
	for(int i=1;i<n;i++)
	{
		f[i][0]=1;
		f[i][1]=0;
		for(int j=i+1;j<=n;j++)
		{
			int k=j-1;
			f[j][0]=f[j][1]=INT_MAX;
			while(a[j]-a[k]<=d&&k>=i)
			{
				if(f[j][1]>f[k][1]+1)
				{
					f[j][1]=f[k][1]+1;
					f[j][0]=f[k][0];
				}
				else f[j][0]+=f[k][0];
				k--;
			}
			if(f[j][0]==2) ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12) cout<<partA()<<"\n";
		else cout<<part1()<<"\n";
	}
	return 0;
}
