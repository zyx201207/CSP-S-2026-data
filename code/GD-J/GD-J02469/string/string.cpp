#include<bits/stdc++.h>
using namespace std;
struct node
{
	char c;
	int x;
};
int n;
long long ans;
vector<node> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	q.assign(n+1,{});
	for(int i=1;i<=n;i++)	cin>>q[i].x>>q[i].c;
	int l=1,r=n;
	while(l<r)
	{
		auto u=q[l],v=q[r];
		if(u.x==v.x)
		{
			l++;
			r--;
		}
		else if(u.x<v.x)
		{
			q[r].x-=u.x;
			l++;
		}
		else
		{
			q[l].x-=v.x;
			r--;
		}
		if(u.c!=v.c)	ans+=min(u.x,v.x);		
	}
	cout<<ans;
	return 0;
} 
