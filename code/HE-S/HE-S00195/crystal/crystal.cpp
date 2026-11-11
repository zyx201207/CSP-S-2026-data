#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,cnt=1,d[500005],h[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		h[a[i]]++;
	}
	sort(a+1,a+n+1);
	d[1]=a[1];
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	cnt=h[a[1]];
	while(1)
	{
		m-=d[cnt]*cnt;
		if(m<0)break;
		cnt+=h[a[cnt+1]];
	}
	cout<<cnt;
	return 0;
}
