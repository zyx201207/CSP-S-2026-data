#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,ans;
//queue<char> q;
struct node 
{
	int x;
	char y;
};
deque<node> q;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		q.push_back({x,y});
		n+=x;
	}
	while(q.size()>1)
	{
		node x=q.front(),y=q.back();
		int cnt=min(x.x,y.x);
		q.front().x-=cnt,q.back().x-=cnt;
		if(x.y!=y.y) ans+=cnt;;
		if(q.front().x==0) q.pop_front();
		if(q.back().x==0) q.pop_back();
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2

2
2 a
3 a

0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

*/
