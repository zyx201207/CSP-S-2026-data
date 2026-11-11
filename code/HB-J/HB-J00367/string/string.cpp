#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],sum,mus,l,r,lsum,rsum,ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum+=a[i];
	//cout<<sum<<' ';
	for(int i=1;i<=n;i++)
	{
		int o;
		if(sum%2)o=sum/2;
		else o=sum/2-1;
		if(mus<=o&&mus+a[i]>sum/2)
		{
			//cout<<i<<'\n';
			for(int j=n;j>i;j--)a[j+1]=a[j],c[j+1]=c[j];
			if(sum%2)a[i+1]=mus+a[i]-sum/2-1,sum--;
			else a[i+1]=mus+a[i]-sum/2;
			a[i]=sum/2-mus,
			n++;
			c[i+1]=c[i];
			break;
		}
		mus+=a[i];
	}
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	r=n+1;
	while(lsum+rsum<sum)
	{
		if(lsum<rsum)
		{
			l++;
			if(c[l]!=c[r])ans+=min(a[l],rsum-lsum);
			//if(l==5)cout<<lsum<<' '<<a[l]<<'\n';
			lsum=lsum+a[l];
			//if(l==5)cout<<lsum<<'\n';
		}
		else if(lsum>rsum)
		{
			r--;
			if(c[r]!=c[l])ans+=min(a[r],lsum-rsum);
			rsum+=a[r];
		}
		else
		{
			l++;
			r--;
			if(c[r]!=c[l])ans+=min(a[l],a[r]);
			lsum+=a[l];
			rsum+=a[r];
		}
		//cout<<l<<' '<<r<<' '<<lsum<<' '<<rsum<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
2
2 a
3 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
4
2 a
2 a
2 a
2 a
5
2 a
2 a
3 a
2 a
2 a
10
39 s
8 r
31 e
35 c
39 x
26 c
12 a
23 d
4 g
11 f
*/
