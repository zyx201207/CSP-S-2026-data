#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int N = 500005;

int n, ans, cnt[209];
ll m, a[N], d[N], dd[N], maxx;
bool flag1 = 1, flag2 = 1;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i]; maxx = max(abs(a[i]), maxx);
	}
	sort(a+1, a+1+n);
	if(a[1] < 0){
		int tmp = -a[1];
		for(int i=1; i<=n; ++i) a[i] += tmp;
	}
	sort(a+1, a+1+n);
	// for(int i=1; i<=n; ++i) cout << a[i] << '\n';
	for(int i=1; i<=n; ++i){
		flag1 &= (a[i] == i);
		d[i] = a[i] - a[i-1];
		flag2 &= (d[i] == d[1]);
	}
	if(n <= 5000){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				d[j] = ((a[i] - a[j] >= 0) ? (a[i] - a[j]) : 1e18);
			}
			sort(d+1, d+1+n);
			ll tmp = 0; int res = 0;
			for(int j=1; j<=n; ++j){
				if(tmp + d[j] > m) break;
				tmp += d[j], ++ res;
			}
			ans = max(res, ans);
		}
		return cout << ans, 0;
	}
//	else if(m <= 1e8 && maxx <= 100){
//		for(int i=1; i<=n; ++i){ // 315275
//			++ cnt[a[i] + 100];
//		}
//		for(int i=0; i<=200; ++i){
//			if(! cnt[i]) continue;
//			for(int j=1; j<=n; ++j){
//				d[j] = (((i - 100) - a[j] >= 0) ? (i - 100 - a[j]) : 1e18);
//			}
//			sort(d+1, d+1+n);
//			ll tmp = 0; int res = 0;
//			for(int j=1; j<=n; ++j){
//				if(tmp + d[j] > m) break;
//				tmp += d[j], ++ res;
//			}
//			ans = max(res, ans);
//		}
//		return cout << ans, 0; // zhe ge jie fa zhen mei shen me wen ti, dan jiu shi xie bu guo ????????? wo shi bu shi nao zi dun le.
//	}
    // dd[0] = dd[1] = 0;
	for(int i=1; i<=n; ++i){
		dd[i] = dd[i-1] + (i-1) * d[i];
	}
	dd[n+1] = 5e18;
	int l = 1;
	for(int r=1; l <= n && r <= n; ){
		// cout << l << ' ' << r << ' ' << '\n';
		while((r <= n) && (dd[r] - dd[l-1] < m) && (dd[1+r] - dd[l-1] <= m)){
			++ r;
		}
		// cout << '\n';
		ans = max(ans, r - l + 1);
		++ l;
	}
	return cout << ans, 0;
}
/*
ti yi:
gei ding 1 chang du wei n de xv lie.
mei ci cao zuo ke yi dan dian +1.
qiu m ci cao zuo nei, zui hou zheng ge xv lie de zhong shu de ping shu de zui da zhi.

e, you shi tan xin a.
qv nian zai zai le "club" shang, jin tian, wo yao duo hui shu yu wo de yi qie!
wan le zhe xia zao le, wo zen me jia le.
wu wu wu.
o zhe shi a-b shu dui!!! wsm wo xiang le 1 h!!!!!
bu dui, WA zui da yang li!!!!!
zhe xia zha fei le!!!!! yi jing 1.5h le!!!!!
10 60 
-60 0 60 -60 60 1 1 1 1 1
wan dan le, bu yao zai tiao le /ll, jiu zhe yang ba.
---
zhe ge dong xi bu tai neng che xiao, suo yi two-pointer bu tai xing a.
hai you 40 min, wo ke yi qie T1 ma. ai.
wo zhen de zhi shi xiang qv yi ci NOIP er yi. ai.
zhe ge ti ru guo shi cheng/huang ti, wo jiu che di AFO le.
wo gai zai na li ting liu? wo wen wo zi ji.
---
AFO 2023.3 to 2026.10. Farewell.
Please relieve me from Depression.
Luogu 1120498 huan yin si xin.
tong shi huan yin zhao wo fa de tie zi xiang wo ti gong yi xie xin li & cheng ji shang de bang zhu ba.
*/
