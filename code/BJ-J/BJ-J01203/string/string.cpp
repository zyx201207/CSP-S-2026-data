#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll d,m,n,l,r,sz,ans;
char s;
deque<pair<long long,char>> q;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>d;
	for(int i = 1;i <= d;i++){
		cin>>m>>s;
		q.push_back({m,s});
		n+=m;
	}
	l = 1,r = n-1;
	while(l < r)
	{
		ll fl = q.front().first;
		char fc = q.front().second;
		ll bl = q.back().first;
		char bc = q.back().second;
		sz = min(fl,bl);
		if(fc != bc)
		{
			ans += sz;
		}
		l += sz,r -= sz;
		q.pop_front();
		q.pop_back();
		if(fl - sz > 0) q.push_front({fl - sz,fc});
		if(bl - sz > 0) q.push_back({bl - sz,bc});
		
	}
	cout<<ans;
	return 0;
}
