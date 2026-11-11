#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],kk[200010],p,ok[40],okl,t,ans;
struct node
{
	int a,v;
}x[200010];
bool cmp(node xx,node yy)
{
	return xx.v>yy.v;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=32;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(kk[j]==p&&((a[j]>>i)&1)) cnt++;
		}
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(kk[j]==p&&((a[j]>>i)&1)) kk[j]++;
			}
			p++;
			ok[++okl]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(kk[i]<p) continue;
		t++;
		x[t].a=a[i];
		for(int j=1;j<=okl;j++) x[t].v+=((a[i]>>ok[j])&1)*(1<<ok[j]);
		//cout<<x[t].v<<endl;
	}
	sort(x+1,x+1+t,cmp);
	ans=(1<<32)-1;
	for(int i=1;i<=m;i++)
	{
		ans&=x[i].a;
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12


*/
