#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[201000];
vector<int> vec;
map<int, int> mp;
struct edge{
	int a, b;
}cnt[200100];
bool cmp(const edge &a1, const edge &b1){
	return a1.a > b1.a;
}
int pre[201000], suf[201000];
 main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool flag = 0;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		if(a[i] != i - 1){
			flag = 1;
		}
		mp[a[i]]++;
		if(!(mp[a[i]] - 1)){
			vec.push_back(a[i]);
		} 
	}
	if(m == 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
		return 0;
	} 
	int ans = 0;
	if(m == n - 1){
		pre[1] = a[1];
		suf[n] = a[n];
		for(int i = 2;i <= n;i++) pre[i] = pre[i - 1] & a[i];
		for(int i = n - 1;i >= 1;i--) suf[i] = suf[i + 1] & a[i];
		int ans = max(suf[2], pre[n - 1]);
		for(int i = 2;i <= n - 1;i++){
			ans = max(ans, suf[i + 1] & pre[i - 1]);
		}
		cout << ans << endl;
		return 0;
	}
	if(!flag){
		cout << n - m << endl;
		return 0;
	}else{
	sort(vec.begin(), vec.end(), greater<int>());
	for(int i : vec){
		if(ans > i) break;
		int now = mp[i];
//		cout << mp[i] << endl;
		if(now >= m) ans = max(ans, i);
		else{
			int cc = 0;
			for(int i1 : vec){
				if(i == i1) continue;
				cnt[++cc].a = (i & i1);
				cnt[cc].b = mp[i1];
			}
			sort(cnt + 1, cnt + cc + 1, cmp);
//			for(int i = 1;i <= cc;i++){
//				cout << cnt[i].b << " ";
//			}
//			cout << endl;
			cc = 0;
			int ans1 = i;
			while(now < m){
				now += cnt[++cc].b;
				ans1 = cnt[cc].a;
//				cout << ans1 << endl;
			}
			ans = max(ans, ans1);
		}
	}
	}
	cout << ans << endl;
} 
/*
10:16 write
ACed da yang li 1 2 3 5
why 4 TLE??and 5 no TLE??
I am gambler and i guess the writer used rand to make the task.
I will get 90pts. pls
oh cout n-m can ac test 4
em i can get (95-eps)?
10:39 got 100+100+(95-eps)+0
95 pls	
11:43 got 100+100+(95-eps)+(56-eps) 
*/
