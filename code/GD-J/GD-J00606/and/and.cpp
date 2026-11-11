#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
struct node
{
	int a,b,c=1;
}f[N];
int n,m,ans,x[N];
int q(int x)
{
	int c=2;
	while(c<=x) c*=2;
	return c-x;
}
bool cmp1(node x,node y)
{	
	return x.a>y.a;
}
bool cmp2(node x,node y)
{
	if(x.b==y.b)
	{
		if(x.a==y.a) return x.c>y.c;
		else return x.a>y.a;
	}
	return x.b<y.b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i].a;
	for(int i=1;i<=n;i++) f[i].b=q(f[i].a);
	if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,f[i].a);
		cout<<ans;
		return 0;
	}
	sort(f+1,f+n+1,cmp1);
	for(int i=2;i<=n;)
	{
		if(f[i].a==f[i-1].a)
		{
			while(f[i].a==f[i-1].a)
			{
				f[i].c+=f[i-1].c,f[i-1].b=1e9;
				if(f[i].c>=m)
				{
					cout<<f[i].a;
					return 0;
				}
				i++;
			}
		}
		else i++;
	}
	sort(f+1,f+n+1,cmp2);
	ans=f[1].a;
	for(int i=1;i<=m;i+=f[i].c) ans&=f[i].a;
	cout<<ans;
	return 0;
} 
