#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define INF 0x3f3f3f3f
#define int ll 
#define PII pair<int,int>
#define rep(k,a,b) for (int k =a;k <= b;k ++ )
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector 
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k -- )

const int N = 2e6+5;

int n , d;
int x[N];
int f[N],g[N];
int R[N];

// int jp[N][22];
// int query(int l,int r)
// {
// 	if (l > r) return 0 ; 
// 	int k = __lg(r-l + 1);
// 	return max(jp[l][k],jp[r-(1<<k) + 1][k]);
// }

namespace bl
{
	PII dist[5005][5005];
void solvemain()
{
	cin >> n >> d;

	
	rep(i,1,n) cin >> x[i];

	rep(i,1,n) 
		rep(j,1,n) dist[i][j] = {INF,INF};
	int j = 1;
	for (int i = 1;i <= n;i ++)
	{
		j = max(j,i);
		while (j + 1 <= n && x[j + 1] - x[i] <= d) {
			j ++ ;
		}

		R[i] = j ; 
		if (j == i)  R[i] = 0 ;
	}
	for (int i = n;i >= 1;i -- )
	{
		if (R[i] == 0)
		{
			dist[i][i] = {0,1};
		}
		else if (R[R[i]] == 0){
			// f[i] = 0 ;g[i] = (R[i] - i +  1);
			dist[i][i] = {0,1};
			for (int j = i  + 1;j <= R[i];j ++ )
				dist[i][j] = {1,1};
		}
		else if (i == R[i] - 1)
		{
			dist[i][i] = {0,1};
			for (int j = i + 1;j <= n;j ++)
				dist[i][j] = dist[i + 1][j],dist[i][j].first ++ ;
		}
		else{
			int x= i,y = R[i],z = R[R[i]];

			int Gxy = R[y - 1];
			int Gxy2 = R[y - 2];
			dist[i][i] = {0,1};
			for (int j = i + 1;j <= n;j ++ )
			{
				if (j <=y) dist[i][j] = {1,1};
				else {
					auto chk = [&](PII &a,PII b,PII c)
					{
						if (a.first > b.first + c.first)a.first = b.first + c.first,a.second = min(b.second * c.second,3ll);
						else if(a.first == b.first + c.first) a.second += min(b.second * c.second,3ll);
						a.second = min(a.second,3ll);

					};
					chk(dist[i][j],dist[i][y],dist[y][j]);
					chk(dist[i][j],dist[i][y-1],dist[y-1][j]);
					if (y-2 != i)
					chk(dist[i][j],dist[i][y-2],dist[y-2][j]);
				}
			}

		}
	}
	ll ans = 0 ;
	for (int i = 1;i <= n; ++ i)
		for (int j = i ;j <= n;j ++ )
		{
				ans += dist[i][j].second == 2;
		}
	cout << ans << endl;

	rep(i,0,n) f[i] = g[i] = R[i] = x[i] = 0 ;

}
};

void solvemain()
{
	cin >> n >> d;

	rep(i,0,n) f[i] = g[i] = R[i] = x[i] = 0 ;
	rep(i,1,n) cin >> x[i];

	int j = 1;
	for (int i = 1;i <= n;i ++)
	{
		j = max(j,i);
		while (j + 1 <= n && x[j + 1] - x[i] <= d) {
			j ++ ;
		}

		R[i] = j ; 
		if (j == i)  R[i] = 0 ;
	}
	// for (int i = 1;i <= n;i ++ ) jp[i][0] = R[i];
	// for (int j = 1;j <= 21;j ++ )
	// 	for (int i = 1;i  + (1<<j) - 1 <= n;i ++ )
	// 		jp[i][j] = max(jp[i][j-1],jp[i+(1<<j-1)][j-1]);
		//f2 g :1
	for (int i = n;i >= 1;i -- )
	{
		if (R[i] == 0)
		{
			g[i] = 1;
			f[i] = 0;
		}
		else if (R[R[i]] == 0){
			f[i] = 0 ;g[i] = (R[i] - i +  1);
		}
		else if (i == R[i] - 1)
		{
			f[i] = f[i + 1];
			g[i] = g[i + 1];
			g[i] ++ ;
		}
		else{
			int x= i,y = R[i],z = R[R[i]];

			int Gxy = R[y - 1];
			int Gxy2 = R[y - 2];
			if (Gxy == z)
			{
				if (Gxy2 == z)
				{
					// have two mid
					g[x] = y- x + 1;

				}
				else{
					// only one
					g[x] = y - x + 1;
					f[x] += z - Gxy2 - 1;
					f[x] += g[y] - (z-y);
				}
			}
			else{
				g[x] = y - x + 1;
				g[x] += g[y] - (Gxy - y + 1);
				//good

				f[x] = Gxy - Gxy2;
				f[x] += f[y];

			}
		}
	}
	ll ans = 0 ;
	rep(i,1,n)ans += f[i];
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);

	auto st = clock();
	int c;cin >> c;
	if (c <= 10)
	{
		int t;cin >> t;
		while (t--) bl::solvemain();
		// return 0 ;
	}else{
	int t ;t =  1;cin >> t;
	while(t--) solvemain();
}

	cerr <<endl <<"Time:"<< double(clock() - st) / CLOCKS_PER_SEC<< "ms" << endl;
	return 0 ;
}