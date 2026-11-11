#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n;
ll m,a[N];
ll b[N],pre[N],ans = 1;
bool flag1 = true,flag2 = true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i)
			flag1 = false;
	}
	if(flag1){
		int idx = 1;
		ll sum = 0;
		while(sum + idx <= m){
			sum += idx;
			idx++;
		}
		cout << min(idx,n) << endl;
		return 0;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		b[i] = a[i] - a[i - 1];
		if(i >= 2 && b[i] != b[i - 1])
			flag2 = false;
	}
	if(flag2){
		int idx = 1;
		ll sum = 0,cha = a[n] - a[n - 1];
		while(sum + idx * cha <= m){
			sum += idx * cha;
			idx++;
		}
		cout << min(idx,n) << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++)
		pre[i] = pre[i - 1] + b[i] * 1LL * (i - 1);
	int l = 1;
	ll sum = 0;
	for(int r = 1;r <= n;){
		while(l <= r && r <= n && pre[r] - pre[l] <= m){
			sum = pre[r] - pre[l];
			ll len = r - l + 1;
			ans = max(ans,len);
			r++;
		}
		while(l <= r && pre[r] - pre[l] > m)
			l++;
		if(l == r)
			r++;
	}
	cout << ans << endl;
	return 0;
}
