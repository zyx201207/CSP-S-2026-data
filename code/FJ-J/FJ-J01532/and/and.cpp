#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int ej[35];
vector<int> v[35];
vector<int> ans;
map<int, bool> mp;
void erjinz(int x, int j) {
	int i=0;
	while(x != 0) {
		ej[i] += x % 2;
		if(x&1) v[i].push_back(j);
		x /= 2;
		i++;
	}
}
void build(int x) {
	for(int i = 0 ; i < v[x].size() ; i++) {
		mp[v[x][i]] = true;
	}
}
bool corret(int x) {
	int k = 0;
	for(int i = 0 ; i < v[x].size() ; i++) {
		if(mp[v[x][i]]) k++;
	}
	return k >= m;
}
int erf(int x) {
	int k = 1;
	if(x == 0) return 1;
	while(x--){
		k *= 2;
	}
	return k;
}
void print() {
	int all_anser = 0;
	for(int i = 0 ; i < ans.size() ; ++i){
		all_anser += erf(ans[i]);
	}
	printf("%lld", all_anser);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 0 ; i < n ; i++) {
		int x;
		scanf("%lld", &x);
		erjinz(x, i);
	}
	for(int i = 30 ; i >= 0 ; i--) {
		if(ej[i] >= m) {
			ans.push_back(i);
			build(i);
			break;
		}
	}
	for(int i = ans[0] - 1 ; i >= 0 ; i--) {
		if(ej[i] >= m) {
			if(corret(i)) {
				ans.push_back(i);
			}
		}
	}
	print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
