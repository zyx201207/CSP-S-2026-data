#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,m,maxx=-1,ans=(1<<31)-1;
int a[N];
struct node{
	bool b[33];
	int c;
}e[N];
int d[33],f[33];
bool cmt(node A,node B)
{
	for(int i=31;i>0;i--)
	{
		if(d[i]>=m&&(A.b[i]||B.b[i]))
		{
			if(A.b[i]&&B.b[i])continue;
			return A.b[i]>B.b[i];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(a[i],maxx);
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		e[i].c=a[i];
		while(a[i]>0)
		{
			e[i].b[cnt]=a[i]&1;
			d[cnt++]+=a[i]&1;
			a[i]>>=1;
		}
	}
	int idx=1;
//	for(int i=31;i>0;i--)if(d[i]>m)f[idx++]=i;
	sort(e+1,e+n+1,cmt);
	for(int i=1;i<=m;i++)
	{
		ans=(e[i].c&ans);
	}
	cout<<ans;
	return 0;
}