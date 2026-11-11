#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5+10;

ll n,m,a[N],ans;
priority_queue<ll> q;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
		q.push(a[i]);
	}
	ans = q.top();
	q.pop();
	m--;
	while(m--)
	{
		int cur = q.top();
		q.pop();
		ans &= cur;
	}
	cout<<ans;
	return 0;
}
