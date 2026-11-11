#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
struct node
{
	int a;
	int t;
	int next;
}k[505];
int w[M] , numk[505];
int c , n , m , d , q , ans , final_ans;
void func(int x , int y , int id)
{
	if(x == y)
	{
		ans += w[y];
		final_ans = max(ans , final_ans);
		return;
	}
	if(k[numk[id]].next != -1)
	{
		ans += k[numk[id]].t;
		func(k[numk[id]].next , y , id);
	}
	for(int j = 1 ; j <= n ; j++)
		for(int i = 1 ; i <= numk[j] ; i++)
			if(k[i].a == x && k[i].next != -1)
			{
				if(j != id)
					ans += w[j] + k[i].t;
				ans += k[i].t;
				func(k[i].next , y , j);
			} 
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
		cin >> w[i];
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> numk[i];
		for(int j = 1 ; j <= numk[i] ; j++)
		{
			cin >> k[j].a >> k[j].t;
			if(j != 1)
				k[j - 1].next = k[j].a;
		}
		k[numk[i]].next = -1;
	}
	for(int i = 1 ; i <= q ; i++)
	{
		int x , y , id;
		cin >> x >> y;
		ans = w[x] , final_ans = 0;
		for(int j = 1 ; j <= n ; j++)
			for(int u = 1 ; u <= numk[j] ; u++)
				if(k[u].a == x)
					id = x;
		func(x , y , id);
		cout << final_ans << "\n";
	}
	return 0;
}
