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

void solvemain()
{
	int n , m;cin >> n >> m ;
	vct<int>a(n + 2);
	rep(i,1,n) cin >> a[i];
	sort(a.begin() + 1,a.begin() + n + 1);
	vct<int> s(n + 2);
	rep(i,1,n) s[i] = s[i - 1] + a[i];
	int j = 1;
	int ans = 0 ;
	for (int i = 1;i <=  n;i ++)
	{	
		while ((i - j + 1) * a[i] - (s[i] - s[j - 1]) > m) j ++ ;
		ans = max(ans,i - j + 1);
	}	
	cout << ans << endl;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);

	auto st = clock();
	int t ;t =  1;
	while(t--) solvemain();


	cerr <<endl <<"Time:"<< double(clock() - st) / CLOCKS_PER_SEC<< "ms" << endl;
	return 0 ;
}