#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	char a;
} c[200005];
int n;
int l,r;
long long cnt=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].l;
		cin>>c[i].a;
	}
	l=1;
	r=n;
	while(l<r)
	{
		int t=min(c[l].l,c[r].l);
		if(c[l].a!=c[r].a)
		{
			cnt+=t;
		}
		c[l].l-=t;
		c[r].l-=t;
		while(c[l].l==0)	l++;
		while(c[r].l==0)	r--;
	}
	cout<<cnt;
}
