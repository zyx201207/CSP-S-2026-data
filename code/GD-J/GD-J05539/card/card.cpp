#include<bits/stdc++.h>
using namespace std;
struct cc{
	long long x,last;
}c[300005];
long long n,m,a[500005],ans[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long l=0;
		for(int j=1;j<=m;j++)
		{
			c[j].x=0;
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			l++;
			b[l]=a[j];
			c[a[j]].x++;
			if(c[a[j]].x>=2 && l>c[a[j]].last)
			{
				c[a[j]].x=1;
				l=c[a[j]].last;
			}
			c[a[j]].last=l;
		}
		for(int j=1;j<=l;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
}
