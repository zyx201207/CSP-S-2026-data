#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
long long sum;
int ans,x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum&=a[i];
		ans=max(ans,a[i]);
	}
	if(m==1)	cout<<ans;
	if(m==n)	cout<<sum;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int n=a[i]&a[j];
				x=max(x,n);
			}
		}
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
