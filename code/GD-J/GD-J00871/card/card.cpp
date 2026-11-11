#include<iostream>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;
const int N = 5e5 + 100;
int a[N];
int tt[N];
int n,m;
unordered_map<int, vector<int>> pos;
int cntpos(int l, int e){
	int ans = 0;
	for(const int& p : pos[e]) if(p >= l) ans++;
	return ans;
}
void solve(int t){
	for(int i = t; i <= n;i++){
		tt[a[i]]++;
		if(cntpos(t, a[i]) > 1){
			i = pos[a[i]].back();
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool nodown = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]].push_back(i);
		if(a[i] < a[i-1]) nodown = false;
	}
	if(nodown){
		for(int i = 1; i <= n; i++){
			tt[a[i]] = i;
		}
	}
	else{
		for(int t = 1; t <= n; t++){
			solve(t);
		}
	}
	for(int i = 1; i <= m; i++){
		cout << tt[i] << ' ';
	}
	return 0;
} 
