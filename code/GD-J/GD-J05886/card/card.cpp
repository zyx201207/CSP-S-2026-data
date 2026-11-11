#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],ans[200010];
vector <int> v[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1;i<=n;i++)cin>>a[i];
	for (int i = 1;i<=n;i++){
		for (int j = i;j<=n;j++){
			bool f = 0;
			for (auto k:v[i]){
				if (k==a[j]){
					f = 1;
					break;
				}
			}if (!f)v[i].push_back(a[j]);
			else {
				while (v[i].back()!=a[j])v[i].pop_back();
			}
		}
	}for (int i = 1;i<=n;i++){
		for (auto j:v[i]){
			if (i==j){
				ans[i]++;
				break;
			}
		}
	}
	for (int i = 1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
