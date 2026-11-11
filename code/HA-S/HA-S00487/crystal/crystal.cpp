#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;
//!!!!!!!!!!!!!!!!别忘了freopen!!!!!!!!!!!!!!!!!!!!!!! 
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n; ll m;
	cin>>n>>m;
	vector<ll> a(n),d(n);
	for(int i=0; i<n; ++i)
		cin>>a[i];
	sort(a.begin(), a.end());
//	for(const ll x : a) cout<<x<<' '; cout<<'\n';
	for(int i=1; i<n; ++i)
		d[i] = a[i] - a[i-1]; // 差分 d 1 ~ n-1
	int ans = 1;
	ll sum = 0, s = 0;
	for(int i=1, j=1; i<n; ++i){
		sum += d[i] * (i - j + 1);
		s += d[i - j + 1];
		while(j <= min(i,n-1) && sum > m){
			sum -= s;   	// 维护序列前 i-j+1 项的前缀和以切换序列 
			s -= d[j];		// 
			++j;   			// 这个奇妙的 j 表示序列开始的位置 
		}
		ans = max(ans, i - j + 2);
	}
	cout<<ans;
	return 0;
}
/*

5 8
-3 -1 2 2 7

4

---

5 8
-7 -1 2 3 7

3

---

我爱我的教练crf 
我爱majiahao
我爱xiaphei
我爱祥子爹
我爱司老师 
我爱古振兴
我爱QY2002
我爱cyj,wyr,sps 
很高兴遇见你们

祝rp++
*/
