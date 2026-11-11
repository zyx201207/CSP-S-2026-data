#include<bits/stdc++.h>
using namespace std;
const long long int N=5e6+10;
long long int a[N],n,m,cnt=0,delta,i;
bool f=1,f1=1;
bool cmp(long long int x,long long int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=2)
		{
			if(a[i]!=a[i-1])
			{
				f=0;
				if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
				{
					f1=0;
				}
			}
		}
	}
	if(f||n==1)
	{
		cout<<n;
		return 0;
	}
	else if(f1)
	{
		i=0;
		delta=abs(a[2]-a[1]);
		while(cnt<=m)
		{
			i++;
			cnt+=i*delta;
		}
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	i=0;
	while(cnt<=m)
	{
		i++;
		delta=abs(a[i+1]-a[i]);
		cnt+=i*delta;
	}
	cout<<i;
	return 0;
}
