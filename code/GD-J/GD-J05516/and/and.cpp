#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+5;

int a[N],p[50],t[N],pw_two[35],t_f[N];
string s[N];
vector<int> v[N],vis;

void change_to(int x,int t){
	vector<int> l;
	while (x){
		l.push_back(x%2);
		x /= 2;
	}
	for (int i=l.size()-1;i>=0;i--){
		if (l[i] == 1)
			p[i]++;
		s[t] += (char)('0' + l[l.size()-1-i]);
	}
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		change_to(a[i],i);
	}
	pw_two[0] = 1;
	for (int i=1;i<=34;i++){
		pw_two[i] = pw_two[i-1] * 2;
	}
	for (int i=50;i>=0;i--){
		if (p[i] >= m){
			vis.push_back(i);
			for (int j=1;j<=n;j++){ 
				if (s[j][i] == '1'){ 
					v[i].push_back(j);
				}
			}
		}
	}
	int ans = pw_two[vis[0]];
	for (int i=0;i<v[vis[0]].size();i++){
		t[v[vis[0]][i]]++;
	}
	for(int i=1;i<vis.size();i++){
		int cnt=0;
		for (int j=0;j<v[vis[i]].size();j++){
			int u = vis[i];
			t_f[v[vis[i]][j]]++;
			if (t[v[u][j]] == 1){
				cnt++; 
			}
		}
		if (cnt >= m){
			ans += pw_two[vis[i]];
			for (int j=0;j<v[vis[i]].size();j++){
				if (t[v[vis[i]][j]]) t_f[v[vis[i]][j]] = -1;
			}
			for (int j=1;j<=n;j++){
				t[j] = 0;
			}
			for (int j=0;j<v[vis[i]].size();j++){
				if (t_f[v[vis[i]][j]] == -1) t[v[vis[i]][j]] = 1;
			}
		}
		for (int j=0;j<v[vis[i]].size();j++){
			t_f[v[vis[i]][j]] = 0;
		}
	}
	cout << ans;
	return 0;
}
