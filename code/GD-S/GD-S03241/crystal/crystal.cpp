#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,maxx=-1e9;
int a[N],cnt,ans,t,l,r,j1;
struct node
{
	int c;
	int x,y;
}s[N];
bool cmp(node x,node y)
{
	return x.x<y.x;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i].c=abs(a[i+1]-a[i])*i;
		s[i].x=i;s[i].y=i+1;		
	}		
	sort(s+1,s+n,cmp);
	for(int i=1;i<n;i++)
	{
		t=m;cnt=0;
		for(int j=i;j<n;j++)
		{
			if(t>=s[j].c)
			{
				cnt++;
				t-=s[j].c;j1=j+1;		
			}
			else continue;
		}
		if(cnt>maxx)
		{
			maxx=max(maxx,cnt);
			l=i;r=j1;
		}
	}
	cout<<r-l+1;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
