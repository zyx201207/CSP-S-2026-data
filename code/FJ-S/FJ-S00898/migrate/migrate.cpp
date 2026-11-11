#include<bits/stdc++.h>
using namespace std;
int c,t,n,s[2000010];
long long a[2000010],f[2000010],ans,d;
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
		ans=0;
		for(int i=1;i<=n;i++)
		{			
			for(int j=i;j<=n;j++)
			{
				s[j]=n+10;
				f[j]=0;
			}
			s[i]=0;
			f[i]=1;			
			for(int j=i;j<=n;j++)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]<=d)
					{
						if(s[k]+1==s[j])
						{
							f[j]+=f[k];
						}
						else if(s[k]+1<s[j])
						{
							f[j]=f[k];
							s[j]=s[k]+1;
						}
					}
					else break;
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(f[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
