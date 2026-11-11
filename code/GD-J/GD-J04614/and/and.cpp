#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0,x=0;
	for(int i=30;i>=0;i--)
	{
		if(x>=m)
		{
			x=0;
			ans+=(1<<i);
			for(int j=1;j<=n;j++)
			{
				if((a[j]&(1<<i))==0) b[j]=1;
				if(i>0&&b[j]==0&&(a[j]&(1<<(i-1)))>0) x++;
			}
		}
		else
		{
			x=0;
			for(int j=1;j<=n;j++) if(i>0&&b[j]==0&&(a[j]&(1<<(i-1)))>0) x++;
		}
	}
	cout<<ans;
	return 0;
}
