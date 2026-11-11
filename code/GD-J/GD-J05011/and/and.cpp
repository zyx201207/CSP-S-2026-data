#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
void bfs()
{
	int ans = -1;
	queue<int> q1,q2,q3;
	q1.push(0);
	q2.push(1);
	q3.push(0);
	while(q2.front() <= n+1)
	{
		int ii = q2.front();
		if(ii <= n && q3.front() < m)
		{
			if(q3.front() == 0)
			{
				q1.push(a[ii]);
				q2.push(ii+1);
				q3.push(q3.front() + 1);
				if(m <= n-ii)
				{
					q1.push(0);
					q2.push(ii+1);
					q3.push(0);
				}
			}
			else {
				q1.push(q1.front() & a[ii]);
				q2.push(ii+1);
				q3.push(q3.front() + 1);
				if(m-q3.front() <= n-ii)
				{
					q1.push(q1.front());
					q2.push(ii+1);
					q3.push(q3.front());
				}
			}
		}
		if(q3.front() == m)
		{
			ans = max(ans,q1.front());
			if(ans == ma)
			{
				cout << ans;
				return;
			}
		}
		q1.pop();
		q2.pop();
		q3.pop();
	}
	cout << ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ma = max(ma,a[i]);
	}
	bfs();
} 
