#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
vector<int> nums[2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		nums[28&1].push_back(a[i]);
	}
	sort(a+1,a+n+1);
	int ans = 0;
	for(int b = 29;b >= 0;b--){
		nums[b&1].clear();
		int cnt = 0;
		for(int i : nums[b-1&1]){
			if((i>>b)&1){
				nums[b&1].push_back(i);
				cnt++;
			}
		}
		if(cnt < m){
			nums[b&1].clear();
			for(int i : nums[b-1&1]) nums[b&1].push_back(i);
		}else{
			ans |= (1<<b);
		}
	}
	cout << ans;
}
