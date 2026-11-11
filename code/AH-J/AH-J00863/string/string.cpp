#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct Node
{
	int x,c;
}t[N];
int n,minn;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int y;
		string s;
		cin>>y>>s;
		t[i].x=y;
		t[i].c=s[0];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(t[l].x>t[r].x)
		{
			if(t[l].c!=t[r].c)minn+=t[r].x;
			t[l].x-=t[r].x;
			r-=1;
		}
		else if(t[l].x==t[r].x)
		{
			if(t[l].c!=t[r].c)minn+=t[l].x;
			r-=1,l+=1;
		}
		else if(t[l].x<t[r].x)
		{
			if(t[l].c!=t[r].c)minn+=t[l].x;
			t[r].x-=t[l].x;
			l+=1;
		}
	}
	cout<<minn;
	return 0;
}
