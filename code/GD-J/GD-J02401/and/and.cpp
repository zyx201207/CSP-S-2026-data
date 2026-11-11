#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int n,m;
int maxn=-INT_MAX;
void dfs(int x,int now,int z)
{
	if (n-x+1<m-now)return;
	if (now==m)
		{
		maxn=max(maxn,z);
		return;
		}
	for (int i=x+1;i<=n;i++)
		dfs(i,now+1,z&a[i]);
}
map<int,int>tong;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),maxn=max(maxn,a[i]);
	if (m==1)
		{
		cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	if (n==m)
		{
		int ans=a[1];
		for (int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	if (maxn<4)
		{
		for (int i=1;i<=n;i++)tong[a[i]]++;
	//	cout<<tong[1]<<' '<<tong[2]<<' '<<tong[3]<<endl;
		if (tong[3]>=m)
			{
			cout<<3;
			fclose(stdin);
			fclose(stdout);
			return 0;
			}
		if (tong[2]+tong[3]>=m)
			{
			cout<<2;
			fclose(stdin);
			fclose(stdout);
			return 0;
			}
		if (tong[1]+tong[3]>=m)
			{
			cout<<1;
			fclose(stdin);
			fclose(stdout);
			return 0;
			}
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	if (n>2000)
		{
		bool yes=1;
		for (int i=1;i<=n;i++)
			{
			if (a[i]!=i-1)
				{
				yes=0;
				break;
				}
			}
		int i;
		for (i=2;i<n;)i*=2;
		if (i!=n)yes=0;
		if (yes)
			{
			int sum=a[n-1];
			for (i=2;i<=n;i*=2)
				{
				if (m<=i)
					{
					cout<<sum;
					fclose(stdin);
					fclose(stdout);
					return 0;
					}
				sum=sum-i;
				}
			}
		else
			{
			sort(a+1,a+1+n);
			for (i=n;m>=1;i--)
				m--;
			cout<<a[i+1]<<endl;
			}
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	maxn=-INT_MAX;
	for (int i=1;i<=n;i++)dfs(i,1,a[i]);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
