#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define PII pair<int,int>
#define rep(k,a,b) for (int k =a;k <= b;k ++ )
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define vct vector
#define endl '\n'
#define sz(a) ((int)a.size())
#define rof(k,a,b) for (int k = a;k >= b;k -- )
const int N = 1e6+5;
vector<int> v[N];

int n ,k ;
int cnt;


void solvemain()
{
	cin  >>n >> k ;
	for (int i = 0 ;i <= n;i ++) v[i].clear();
	vct<PII> e;
	rep(i,1,n - 1)
	{
		int x,y;cin >> x >> y;
		v[x].pb(y);v[y].pb(x);e.pb({x,y});
	}
	int minn = INF;
	for (int st = 0; st <(1<<n);st++){
		int V = 0,E = 0 ;
		for (int i = 1;i <= n;i ++ )
		{
			if(st >> i & 1)
			{
				V ++ ;
				for (auto j : v[i]) if (st >> j & 1) E ++ ;
			}
		}
		E /= 2;
		if (V <= E + 2 && __builtin_popcount(st) == k)
		{
			queue<int> q;
			vct<int> d(n +1,INF);
			d[0] = 0 ;
			for (int i = 1;i <= n;i ++ )
			if(st >> i & 1) d[i] = 0,q.push(i);
			while (sz(q))
			{
				int x = q.front();q.pop();
				for (auto y : v[x])
				{
					if (d[x] + 1 < d[y])
					{
						d[y] = d[x] + 1;
						q.push(y);
					}
				}
			}
			minn = min(minn, *max_element(all(d)));
			// if (minn == 1) cout <<st << endl;

		}
	}
	cout << minn << endl;

}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);

	auto st = clock();
	int t ;t =  1;
	int c;cin >> c>> t;
	while(t--) solvemain();


	cerr <<endl <<"Time:"<< double(clock() - st) / CLOCKS_PER_SEC<< "ms" << endl;
	return 0 ;
}
