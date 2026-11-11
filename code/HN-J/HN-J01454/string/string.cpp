#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 2e5 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int n;
int a[maxn];
char c[maxn];
ll ans = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	pre(i, 1, n)
	{
		scanf("%d", &a[i]);
		cin>>c[i];
	}
	int front = 1, rear = n;
	while(front <= rear)
	{
//		if(front == rear)
//		{
//			break;
//		}
		if(c[front] != c[rear])
		{
			if(a[front] <= a[rear])
				ans += a[front], a[rear] -= a[front], ++front;
			else
				ans += a[rear], a[front] -= a[rear], --rear; 
		}
		else
		{
			if(a[front] <= a[rear])
				a[rear] -= a[front], ++front;
			else
				a[front] -= a[rear], --rear;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

