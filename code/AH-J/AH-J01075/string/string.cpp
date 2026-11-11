#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long L=0;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>c[i],L+=a[i];
	long long res=L/2,ans=0,now=n;
	for(int i=1;i<=n;i++)
	{
		long long d=min(a[i],res);
		res-=d;
		while(d>=a[now])
		{
			d-=a[now];
			if(c[now]!=c[i])ans+=a[now];
			now--;
		}
		if(c[now]!=c[i])ans+=d;
		a[now]-=d;
	}
	cout<<ans;
	return 0;
}
