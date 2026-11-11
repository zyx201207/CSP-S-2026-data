#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[500005],b[500005];
long long k=0;
int ef(int n,int l,int r)
{
	while(l<r)
	{
		int mi=l+(r-l)/2;
		if(a[mi]>n)
		{
			r=mi;
		}
		else
		{
			l=mi+1;
		}
	}
	if(l>=r)
	{
		return r;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j,x;
	long long m;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k+=a[i];
	}
	sort(a+1,a+n+1);
	int k1=k/(n*(long long) 1);
	k1=ef(k1,1,n);
	//cout<<k<<' '<<k1<<' '<<a[k1]<<endl;
	for(i=1;i<=n;i++)
	{
		//cout<<a[i]<<' ';
		b[i]=abs(a[i]-a[k1]);
	}
	//cout<<endl;
	sort(b+1,b+n+1);
	/*for(i=1;i<=n;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;*/
	for(i=1;i<=n;i++)
	{
		if(m>=b[i])
		{
			m-=b[i];
			//cout<<m<<' ';
			ans++;
		}
		else
		{
			break;
		}
	}
	/*for(i=1;i<=3845;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;*/
	printf("%lld",ans);
	return 0;
}
