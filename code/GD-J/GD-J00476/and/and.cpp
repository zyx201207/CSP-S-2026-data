#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <int> f[32];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		int tmp = a[i],cnt = 0;
		while(tmp){
			if(tmp & 1) 
				f[cnt].push_back(i);
			tmp /= 2,cnt++;
		}
	}
	int zs = -1;
	for (int i = 31;i >= 0;i--){
		if(f[i].size() >= m) {
			zs = i;
			break;
		}
	}
	vector <int> dx;
	for (int i = 0;i < f[zs].size();i++)
		dx.push_back(f[zs][i]);
	int ans = (1 << zs);
	for (int i = zs - 1;i >= 0;i--){
		unordered_map <int,bool> mp;
		for (int j = 0;j < dx.size();j++)
			mp[dx[j]] = 1;
		vector <int> tmp;
		int cnt = 0;
		for (int j = 0;j < f[i].size();j++){
			if(mp[f[i][j]] == 1)
				tmp.push_back(f[i][j]);
		}
		if(tmp.size() >= m){
			dx = tmp;
			ans += (1 << i);
		}
	}
	printf("%d",ans);
	return 0;
}
	
