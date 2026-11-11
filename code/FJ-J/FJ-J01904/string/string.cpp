#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
vector<int> ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			ans.push_back(c[i]);
		}
	}
	int res = 0;
	int len = ans.size();
	for(int i = 0;i < len / 2;i++){
		if(ans[i] != ans[len - i - 1]){
			res++;
		}
	}
	cout << res;
	return 0;
}
