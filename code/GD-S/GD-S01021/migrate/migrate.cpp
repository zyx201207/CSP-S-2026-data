#include<bits/stdc++.h>
#define int long long
using namespace std;

int C,T,n,m,a[2000010],pre[2000010];
int d[2000010],cnt[2000010],s[2000010],last[2000010];
int t[2000010];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int l=1;
		for(int r=1;r<=n;r++)
		{
			while(a[r]-a[l]>m) l++;
			pre[r]=l;
		}
		if(C<=10)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				d[i]=0;cnt[i]=1;
				last[0]=i;
				s[i-1]=0;s[i]=1;
				for(int j=i+1;j<=n;j++)
				{
					if(pre[j]==j) break;
					int k=pre[j];
					int l=last[d[k]];
					d[j]=d[k]+1;
					cnt[j]=s[l]-s[k-1];
					s[j]=s[j-1]+cnt[j];
					last[d[j]]=j;
					if(cnt[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		if(C==11 || C==12)
		{
			int ans=0;
			d[1]=0;cnt[1]=1;
			s[1]=1;last[0]=1;
			for(int i=2;i<=n;i++)
			{
				if(pre[i]==i) break;
				int j=pre[i];
				int k=last[d[j]];
				d[i]=d[j]+1;
				cnt[i]=s[k]-s[j-1];
				s[i]=s[i-1]+cnt[i];
				last[d[i]]=i;
				t[i]=t[i-1]+(cnt[i]==2);
				ans+=t[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
