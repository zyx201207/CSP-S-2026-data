#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],c[32];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i],k=1;
		while(tmp!=0)
		{
			c[k]+=(tmp&1);
			tmp>>=1,k++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=0,k=1;
		while(a[i]!=0)
		{
			if(c[k]>=m and (a[i]&1)==1)tmp+=(1<<(k-1));
			k++,a[i]>>=1;
		}
		a[i]=tmp;
	}
	sort(a+1,a+n+1);
	int ans=(1<<30)-1;
	for(int i=n;i>=n-m+1;i--)
	  ans&=a[i];
	cout<<ans;
	return 0;
}
