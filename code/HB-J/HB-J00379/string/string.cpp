#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
int n,RP;
struct node{
	int v;
	string c;
}a[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].c;
	}
	int fr=1,ba=n;
	int no=0;
	while(fr<ba)
	{
		no+=a[fr].v;
		int x=a[fr].v;
		while(x)
		{
			if(a[ba].c!=a[fr].c)
				RP+=min(a[ba].v,x);
			int _x=x;
			if(a[ba].v>x)
				x=0;
			else
				x-=a[ba].v;
			if(a[ba].v<=_x)
				ba--;
			else
				a[ba].v=a[ba].v-_x;
		}
		fr++;
	}
	cout<<RP;
	return 0;
}
//RP++
