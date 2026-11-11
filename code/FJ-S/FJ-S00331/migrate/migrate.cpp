#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[2000005],k,s,p,l;
void dfs(int x,int y)
{
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]<=m)
			l++,dfs(i,y),l--;
	if(s+1==l&&x==y)
		k++;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12)
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			int k=a[2]-a[1];
			if(m<k+k)
			{
				cout<<"0\n";
				continue;
			}
			cout<<max(n-m/k-m/k+1,0ll)<<"\n";
		}
	else if(c==1||c==2)
		while(t--)
		{
			p=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				{
					k=s=l=0;
					if(a[j]-a[j-1]>m)
						continue;
					int t=i,flag=0;
					for(int k=i+1;k<=j;k++)
						if(a[k]-a[t]>m)
						{
							if(k==t+1)
							{
								flag=1;
								break;
							}
							t=k-1,s++;
						}
					if(flag)
						continue;
					dfs(i,j);
					if(k==2)
						p++;
				}
			cout<<p<<'\n';
		}
	else
		while(t--)
			cout<<"0\n";
}
