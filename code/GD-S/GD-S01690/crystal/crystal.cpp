/*
排序 
枚举要变成的值
双指针找到最左侧差值之和不超过 m 的后缀 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N];
int n;
ll m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a + 1,a + n + 1);
	int res = 0;
	ll t = 0;
	for(int i=1,j = 1;i<=n;i++){
		t += 1ll * (i - j) * (a[i] - a[i - 1]);
		while(t > m){
			t -= a[i] - a[j];
			j++;
		}
		res = max(res,i - j + 1);
	}
	cout<<res;
	return 0;
}
