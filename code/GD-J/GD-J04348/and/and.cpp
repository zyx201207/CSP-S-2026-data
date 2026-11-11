#include<iostream>
#include<vector>
using namespace std;
void dfs(int& ans , vector<int>& v , int pos , int m , int now){
	if(pos == v.size() - 1 && m > 0) return;
	if(m < 0) return;
	if(m == 0){
		ans = max(ans , now);
		return;
	}
	if(now == 0) dfs(ans , v , pos + 1 , m - 1 , v[pos]);
	else dfs(ans , v , pos + 1 , m - 1 , (now & v[pos]));
	dfs(ans , v , pos + 1 , m , now);
}
int main(){
	frepen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	vector<int> v(n);
	for(int& num : v) cin >> num;
	int ans = 0;
	dfs(ans , v , 0 , m , 0);
	cout << ans;
	return 0;
}
