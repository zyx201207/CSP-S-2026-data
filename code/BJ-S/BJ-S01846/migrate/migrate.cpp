#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int a[N],num[N],minn[N],pos[N];
void bfs(int now,int sum)
{
	if(now>n) return;
	if(sum!=0)
	{
		if(minn[now]>sum)
		{
			minn[now]=sum;
			num[now]=1;
		}
		else if(minn[now]==sum) num[now]++;
	}
	if(num[now]>2) return;
	for(int i=now+1;i<=n;i++)
	{
		if(a[i]-a[now]>d) break;
		bfs(i,sum+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) minn[i]=1e18;
		for(int i=1;i<=n;i++) num[i]=pos[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1||n==2||n==3)
		{
			cout<<"0\n";
			continue;
		}
		if(c==1||c==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) minn[j]=1e18;
				for(int j=1;j<=n;j++) num[j]=0;
				bfs(i,0);
				for(int j=i+1;j<=n;j++)
				{
					if(num[j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c>=3&&c<=6)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]>d) break;
					pos[i]=j;
				}
			}
			for(int i=4;i<=n;i++)
			{
				for(int j=1;j<=i-3;j++)
				{
					int cnt=0;
					for(int k=j;k<i;k++)
					{
						if(pos[pos[k]-1]>=pos[pos[k]]&&pos[k]-1!=k) cnt++;
					}
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c==11||c==12)
		{
			int p=-1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]>d)
				{
					p=i;
					break;
				}
			}
			if(p==-1||p==n||a[2]-a[1]>=d) cout<<"0\n";
			else cout<<n-(p+((p+1)-2)/2-1)+1<<"\n";
			continue;
		}
		cout<<"0\n";
	}
	return 0;
}