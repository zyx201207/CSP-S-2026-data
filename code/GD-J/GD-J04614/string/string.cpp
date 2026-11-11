#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
struct N
{
	long long l,r;
	char c;
}b[200005],d[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long s=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];s+=a[i];
		b[i]={b[i-1].r+1,b[i-1].r+a[i],c[i]};
	}
	for(int i=n;i>=1;i--) d[n-i+1]={d[n-i].r+1,d[n-i].r+a[i],c[i]};
	int x=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i].l>s/2) break;
		b[i].r=min(b[i].r,s/2);
		while(d[x].r<b[i].r)
		{
			if(d[x].c!=b[i].c&&d[x].r>=b[i].l) ans+=d[x].r-max(d[x].l,b[i].l)+1;
			x++;
		}
		if(d[x].c!=b[i].c) ans+=b[i].r-max(d[x].l,b[i].l)+1;
	}
	cout<<ans;
	return 0;
}
