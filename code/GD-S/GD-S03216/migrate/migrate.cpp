#include<bits/stdc++.h>
using namespace std;
long long n,m,d,a[1000005],f[100005],l[100005],p[100005],r[1000005],ans,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c2;
	cin>>c2>>T;
	for(int i2=1;i2<=T;i2++)
	{
			cin>>n>>d;
			ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		long long cnt=i,cnt1=i,cnt2=1;
		for(int j=i;j<=n;j++)
		{
			if(j==i)
			{
				f[j]=1;
				l[j]=1;
				continue;
			}
			while(a[j]-a[cnt1]>d)
			{
			cnt2-=l[cnt1];
				cnt1++;
				if(f[cnt1]!=f[cnt1-1])
				{
					cnt2=p[f[cnt1]];
				}
			}
			if(cnt1>=j)
			break;
			f[j]=f[cnt1]+1;
			l[j]=cnt2;
			p[f[j]]+=cnt2;
			if(l[j]==2)
			ans++;
		}
		for(int j=1;j<=n;j++)
		{
			f[j]=0;
			l[j]=0;
			p[j]=0;
		}
	}
	cout<<ans<<"\n";
	}

	return 0;
}
