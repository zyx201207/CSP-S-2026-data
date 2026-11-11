#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,sum,c,ans=1,t,minn=INT_MAX;
struct node{
	long long num,d;
}a[N];
bool cmp(node a,node b)
{
	return a.d<b.d;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].num);
		sum+=a[i].num;
	}
	sum=sum/n;
	for(i=1;i<=n;i++)
	{
		int s=abs(a[i].num-sum);
		if(s<minn)
		{
			minn=s;
			t=a[i].num;
		}
	}
	for(i=1;i<=n;i++)
	{
		a[i].d=abs(a[i].num-t);
	}
	sort(a+1,a+n+1,cmp);
	for(i=2;i<=n;i++)
	{
		if(c+a[i].d<=m)
		{
			c=c+a[i].d;
			ans++;
		}
		if(c==m)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
