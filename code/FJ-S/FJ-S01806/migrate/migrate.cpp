#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
long long c,W,n,d,a[200005],ans;
struct node
{
	long long step,id;
};
void bfs(long long x,long long y)
{
	queue <node> q;
	long long ste[200005],t[200005];
	for(int i = 1;i<=n;i++)
		ste[i]=100000000;
	for(int i = 1;i<=n;i++)
		t[i]=0;
	q.push({0,x});
	while(!q.empty())
	{
		node b = q.front();
		q.pop();
		long long w = b.id+1;
		while(a[w]-a[b.id]<=d&&w<=y)
		{
			if(b.step+1<=ste[w])
			{
				q.push({b.step+1,w});
				ste[w]=b.step+1;
				t[w]++;
			}
			w++;
		}
	}
	for(int i = x+3;i<=y;i++)
	{
		if(t[i]==2) ans++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> W;
	while(W--)
	{
		ans=0;
		cin >> n >> d;
		for(long long i = 1;i<=n;i++)
		{
			cin >>a[i];
		}
		for(long long i = 1;i<=n-3;i++)
		{
			bfs(i,n);
		}
		cout << ans << "\n";
	}
	return 0;
} 
