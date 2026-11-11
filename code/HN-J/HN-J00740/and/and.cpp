#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
	long long x,sm;
};
long long a[N];
vector<Node> b[N];

long long get_s(long long x)
{
	long long sum = 0;
	while(x)sum++,x /= 2;
	return sum;
}
long long get_mx(long long x)
{
	long long sx = 0,k = 0;
	while(x)
	{
		k++;
		if(x / 2 > 0 && x % 2 == 1)sx = k;
		x /= 2;
	}
	return sx;
}
bool cmp(Node a,Node b)
{
	if(a.sm == b.sm)return a.x > b.x;
	return a.sm > b.sm;
}
map<long long,int> mp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans = 0;
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)cin>>a[i],mp[a[i]]++;
	sort(a + 1,a + n + 1);
	n = unique(a + 1,a + n + 1) - (a + 1);
	for(int i = 1 ; i <= n ; i++)
	{
		long long y = get_s(a[i]),p = get_mx(a[i]);
		b[y].push_back({a[i],p});
	}
	for(int i = 0 ; i < 40 ; i++)sort(b[i].begin(),b[i].end(),cmp);
	for(int i = 35 ; i >= 0 ; i--)
	{
		long long ans1 = -1,y = m;
		if(b[i].empty())continue;
		for(int j = 0 ; j < b[i].size() ; j++)
		{
			int x = b[i][j].x;
			if(ans1 == -1)ans1 = x;
			else ans1 &= x;
			y -= mp[x];
			if(y <= 0)break;
		}
		long long t = ans1;
		for(int p = 0 ; p < 35 && t >= ans1 ; p++)
		{
			t = (1 << get_s(t)) + t;
			y -= mp[t];
		}
		if(y <= 0)ans = max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
