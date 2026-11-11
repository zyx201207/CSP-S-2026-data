#include<bits/stdc++.h>
using namespace std;
int n, a[200005], m, res;
vector<int> s[35], ans, tmp;
vector<int> merge(vector<int> x, vector<int> y){
	vector<int> ss;
	auto px = x.begin(), py = y.begin();
	for(;px != x.end(), py != y.end();){
		if(*px == *py){
			ss.push_back(*px);
			px++; py++;
		}else if(*px < *py) px++;
		else py++;
	}
	return ss;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d" ,&n ,&m);
	for(int i = 1;i <= n;i++) scanf("%d" ,&a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1, pos;i <= n;i++){
		ans.push_back(i);
		pos = 0;
		while(a[i]){
			if(a[i] & 1) s[pos].push_back(i);
			a[i] >>= 1;
			pos++;
		}
	}
	for(int i = 30, siz;i >= 0;i--){
		tmp = merge(ans, s[i]);
		siz = tmp.size();
		if(siz < m) continue;
		res += (1 << i);
		ans = tmp;
	}
	printf("%d" ,res);
	return 0;
}
