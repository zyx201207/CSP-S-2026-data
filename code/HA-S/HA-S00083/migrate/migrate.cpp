#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,l[N],r[N];
long long a[N],minn,num,ed,dd;
void dfs(int x,int p)
{
	if(x==ed)
	{
		if(minn>p)
		{
			minn=p;
			num=1;
		}
		else
			num++;
		return;
	}
	for(int i=x+1;i<=ed&&a[i]-a[x]<=dd;i++)
		dfs(i,p+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=3)
		{
			cout<<"0\n";
			continue;
		}
		if(n<=9)
		{
			dd=d;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
					minn=1e9;
					num=0;
					ed=j;
					dfs(i,0);
					if(num==2)
						ans++;
				}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<i&&a[i]-a[j]>d)
				j++;
			l[i]=j;
		}
		for(int i=n,j=n;i>=1;i--)
		{
			while(j>i&&a[j]-a[i]>d)
				j--;
			r[i]=j;
		}
		for(int i=1,j,k;i<=n;i++)
		{
			j=i+2;
			while(j<=n&&l[j]!=j&&(l[l[j]]<i||r[l[l[j]]]-l[j]!=1))
				j++;
			if(l[j]==j)
				continue;
			if(j==n+1)
				break;
			k=j+1;
			while(k<=n&&l[k]!=k&&((r[l[l[k]]]-l[k]<1&&l[l[k]]>=j)||(r[l[l[k]]]-l[k]<=1&&l[l[k]]<j)))
				k++;
			ans+=k-j;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
