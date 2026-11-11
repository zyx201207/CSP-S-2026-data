#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+10;
int a[N], to[M];
int vis[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> vec(n, 0);
		memset(vis, 0, sizeof vis);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]] = j;
				vec[j-1] = a[j];
			}
			else{
				for(int k=vis[a[j]]-1;k<j;k++){
					vis[vec[k]] = 0;
					vec[k] = 0;
				}
				vis[a[j]] = j;
				vec[j-1] = a[j];
			}
		}
		for(int j=0;j<n;j++){
			if(vec[j] > 0){
				to[vec[j]] +=1;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout << to[i] << " ";
	}
	return 0;
}
