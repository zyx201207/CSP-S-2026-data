#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> res,tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		int a;
		cin >> a;
		res.emplace_back(a);
	}
	for (int i = 30;i >= 0;i--){
		for (int j : res)
			if (j & (1 << i))
				tmp.emplace_back(j);
		if ((int)tmp.size() >= m)
			res = tmp;
		tmp.clear();
	}
	int ans = (1 << 30) - 1;
	for (int i = 0;i < m;i++)
		ans &= res[i];
	cout << ans << endl;
	return 0;
}

