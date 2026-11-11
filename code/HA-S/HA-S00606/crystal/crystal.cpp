#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],sum,minn=1e9,mid,midi=2,cnt,m;
bool cmp(int x,int y)
{
	return abs(x-mid) < abs(y-mid);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum+=a[i];
	sum/=n;
	for(int i=1;i<=n;i++)
		minn=min(minn,abs(a[i]-sum));
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-sum)==minn)
		{
			mid=a[i];
			break;
		}
	}
	sort(a+1,a+n+1,cmp);
	while(m>0)
	{
		if(m>=abs(a[midi]-mid))
		{
			m-=abs(a[midi]-mid);
			a[midi]=mid;
		}
		else
			break;
		midi++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mid)
			cnt++;
	}
	cout<<cnt;
	return 0;
}
