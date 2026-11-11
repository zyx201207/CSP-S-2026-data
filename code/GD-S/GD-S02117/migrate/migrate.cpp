#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n-2;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				set<int> s1,s2;
				int k=i;
				s1.insert(k);
				while(k<j)
				{
					int kk=j;
					while(a[kk]-a[k]>d) kk--;
					if(kk==k) break;
					k=kk;
					s1.insert(kk);
				}
				if(k!=j) continue;
				s2.insert(k);
				while(k>i)
				{
					int kk=i;
					while(a[k]-a[kk]>d) kk++;
					if(kk==k) break;
					k=kk;
					s2.insert(kk);
				}
				if(s1!=s2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
