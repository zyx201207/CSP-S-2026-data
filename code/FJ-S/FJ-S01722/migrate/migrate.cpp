#include<bits/stdc++.h>
using namespace std;
int t,n,d,r,c;
int a[1000010];
long long ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i]; 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int o=0,p=0,l=0;
					p=i+1;
					while(a[p]-a[i]<=d&&p<j) p++;
					if(p>2||j-i<=2||p==0)
					{
						o=1;
						break; 
					}
					if(p==2) l++; 
				if(!o&&l==1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
