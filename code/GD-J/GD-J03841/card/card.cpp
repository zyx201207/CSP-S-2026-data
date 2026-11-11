#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for (int i = 1; i <= n; i++){
		v.clear();
		for (int j = i; j <= n; j++){
			bool t = false;
			for (int l = 0; l < v.size(); l++){
				if (v[l] == a[j]){
					t = true;
					break;
				}
			}
			if (t){
				int len = v.size();
				len--;
				while (v[len] != a[j]){
					v.pop_back();
					len--;
				}
				v.pop_back();
			}
			v.push_back(a[j]);
		}
		for (int j = 0; j < v.size(); j++){
			c[v[j]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
