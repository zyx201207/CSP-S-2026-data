#include <vector>
#include <iostream>

using namespace std;

const int N = 500010;

int n, m;
int res[N];
int seq[N];
int nxtval[N];
int valpos[N];
int sub[N], nxt[N]; 
vector <int> pos[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i )
	{
		cin >> seq[i];
		pos[seq[i]].push_back(i);
	}
	
	for (int i = 1; i <= m; ++ i )
		for (int j = 1; j < pos[i].size(); ++ j )
			nxt[pos[i][j - 1]] = pos[i][j];
	
	for (int i = 1; i <= n; ++ i )
	{
		int start = i;
		while (start <= n)
		{
			int tmp = start;
			while (tmp <= n && !nxt[tmp])
				tmp ++ ;
			if (tmp > n || !nxt[tmp])
			{
				sub[start] ++ ;
				break;
			}
			sub[start] ++ , sub[tmp] -- ;
			sub[nxt[tmp]] ++ , sub[nxt[tmp] + 1] -- ;
			start = nxt[tmp] + 1; 
		}
	}
	
	for (int i = 1; i <= n; ++ i )
		sub[i] += sub[i - 1];
	
	for (int i = 1; i <= n; ++ i )
		res[seq[i]] += sub[i];
	
	for (int i = 1; i <= m; ++ i )
		cout << res[i] << " ";
//	cout << n;
		
//	for (int i = 1; i <= n; ++ i )
//		printf("%d ")
	
	return 0;
}
