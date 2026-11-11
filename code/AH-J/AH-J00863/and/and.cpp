#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int pw[35],n,m,sum[35];
struct Node
{
	bool t[35];
	int x,w;
}a[N];
void init()
{
	pw[0]=1;
	for(int i=1;i<=30;i++)
		pw[i]=2*pw[i-1];
	
}
bool cmp(Node l,Node r)
{
	return l.x>r.x;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		int p=a[i].x,j=0;
		while(p>0)
		{
			a[i].t[j]=p%2;
			if(a[i].t[j]) sum[j]++;
			p>>=1;
			a[i].w++;
			j++;
		}
	}
	init();
	for(int i=30;i>=0;i--)
	{
		if(sum[i]<m) 
			for(int j=1;j<=n;j++)
				if(a[j].t[i]&&i<a[j].w) 
					a[j].x-=pw[i];
	}
	sort(a+1,a+1+n,cmp);
	int top=a[1].x;
	for(int i=1;i<=m;i++)
		top=top&a[i].x;
	cout<<top;
	return 0;
}
