#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
vector<int> a;
struct w {
	vector<int> ak;
	vector<bool> b;
};
void dfs() {
	stack<w> allkill;
	allkill.push({vector<int> (),vector<bool> (n+1,0)});
	while (!allkill.empty()) {
		vector<int> ak=allkill.top().ak;
		vector<bool> b=allkill.top().b;
		allkill.pop();
		if (ak.size()==m) {
			int aa=ak[0];
			for (int i=1; i<ak.size(); i++) {
				aa&=ak[i];
			}
			ans=max(ans,aa);
		} else {
			for (int i=1; i<=n; i++) {
				if (!b[i]) {
					vector<int> allak=ak;
					allak.push_back(a[i]);
					vector<bool> bothak=b;
					bothak[i]=1;
					allkill.push({allak,bothak});
				}
			}
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a=vector<int> (n+1,0);
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if (m==1) {
		int maxn=a[1];
		for (int i=2; i<=n; i++) {
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	} else if (m==n) {
		int ans=a[1];
		for (int i=2; i<=n; i++) {
			ans=ans&a[i];
		}
		cout<<ans;
	} else {
		dfs();
		cout<<ans;
	}
	return 0;
}

