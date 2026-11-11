#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 , M = 3e5 + 5;
int n , m;
int a[N];
int lst[N];
int g[M];
bool vis[M];
int que[N];
int ans[N];
int main()
{
//	freopen("card.in" , "r" , stdin) , freopen("card.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	reverse(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i++)
		lst[i] = g[a[i]] , g[a[i]] = i;
	int head = 1 , tail = 0;
	for(int i = n;i >= 1;i--)
	{
		while(vis[a[i]] == 1 && que[tail] != a[i])
		{
			vis[que[tail]] = 0;
			tail--;
		}
		if(que[tail] != a[i])que[++tail] = a[i] , vis[a[i]] = 1;
		for(int j = 1;j <= tail;j++)ans[que[j]]++;
	}
	for(int i = 1;i <= m;i++)cout<<ans[i]<<" "; 
	return 0;
}
