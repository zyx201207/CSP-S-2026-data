#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 505000;
ll n,m,i,j,k,a[N],cnt[N],f[N],ans[N],vis[N],shang,x;
vector<int>las[N];
vector<int>v;
int main()
{
//	int task = 6;
//	string filename = "card"+to_string(task)+".in";
//	freopen(filename.c_str(),"r",stdin);
//	freopen("card.out","w",stdout);
//	cout << filename << endl;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (i=1; i<=n; i++) cin >> a[i];
	shang = 0;
	for (i=n; i>=1; i--)
	{
		x = a[i];
		if (vis[x] == 0)
		{
			vis[x] = 1;
			las[x] = las[shang];
			las[x].push_back(x);
		}
		cnt[x] ++;
		shang = x;
	}
	for (i=1; i<=m; i++)
	{
		for (auto j:las[i])
		{
			ans[j] += cnt[i];	
		} 
	}
	for (i=1; i<=m; i++)
		cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


