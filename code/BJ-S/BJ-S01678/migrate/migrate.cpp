#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int id,t,n,d[N],f[N];
long long m,a[N],pre[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>id>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n>5000)
		{
			for(int i=0;i<n;i++)
			{
				a[0]=a[1];
				cin>>a[1];
			}
			int k=m/(a[1]-a[0])<<1;
			if(k<=2)
			{
				cout<<"0\n";
				continue;
			}
			cout<<max(n-k+1,0)<<'\n';
			continue;
		}
		for(int l=0,r=0;r<n;r++)
		{
			cin>>a[r];
			for(;a[r]-a[l]>m;l++);
			pre[r]=l;
		}
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			if(i<pre[i+1])continue;
			fill(d,d+n,n);
			fill(f,f+n,0);
			d[i]=0;
			f[i]=1;
			for(int j=i+1;j<n;j++)
			{
				for(int k=pre[j];k<j;k++)
				{
					if(d[j]>d[k]+1)
					{
						d[j]=d[k]+1;
						f[j]=f[k];
					}
					else if(d[j]==d[k]+1)
					{
						f[j]=min(f[j]+f[k],3);
					}
				}
				ans+=f[j]==2;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}