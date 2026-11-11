#include<bits/stdc++.h>
using namespace std;
struct node
{
	int cnt;
	char c;
}a[200005];
int n,l,r;
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].cnt>>a[i].c;
	l=1,r=n;
	while(l<r)
	{
		if(a[l].cnt==a[r].cnt)
		{
			if(a[l].c!=a[r].c)
				ans+=a[l].cnt;
			l++;r--;
		}
		else if(a[l].cnt>a[r].cnt)
		{
			if(a[l].c!=a[r].c)
				ans+=a[r].cnt;
			a[l].cnt-=a[r].cnt;
			r--;
		}
		else
		{
			if(a[l].c!=a[r].c)
				ans+=a[l].cnt;
			a[r].cnt-=a[l].cnt;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
