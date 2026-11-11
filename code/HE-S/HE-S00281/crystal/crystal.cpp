#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int mm=m;
	for(int i=1;i<=n;++i)
	{
		m=mm;
		int num=0;
		for(int j=1;j<=n;++j)
		{
			b[j]=abs(a[i]-a[j]);
		}
		sort(b+1,b+n+1);		
		int l=1;
		while(l<=n)
		{
			if(!(m-b[l]<0)&&b[l]>=0)
			{
				m-=b[l];
				l++;
				num++;
			}
			else{
				m-=b[l];
				l++;
			}
		}
		maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
}
