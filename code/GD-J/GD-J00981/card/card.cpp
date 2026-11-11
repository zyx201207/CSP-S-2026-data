#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int bj[500005];
int d[500005],l;
int wz[500005];
int cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		memset(wz,0,sizeof(wz));
		l=0;
		for(int j=i+1;j<=n;j++)
		{
			l++;
			if(wz[a[j]]!=0) l=wz[a[j]];
			d[l]=a[j];
			wz[a[j]]=l;
		}
		for(int j=1;j<=l;j++)
		{
			cnt[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" "; 
	}
	return 0;
}
