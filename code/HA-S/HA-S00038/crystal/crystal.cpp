#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
typedef pair<int, int> PII;
/*
二分？ 
最大值*mid - sum 
*/
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 5;
int n, m, a[N];
int arr[N];
inline bool check(int x){
	int minn = INF;
	for(int i = x; i <= n; i++) minn = min(minn, a[i] * x - (arr[i] - arr[i - x]));
	return minn <= m;
}
inline void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) arr[i] = arr[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1; 
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

/*
众星因你，皆降为尘
华风夏韵，洛水天依
乐正司百曲，绫动万年红
言起一人歌，歌起万人和

luogu 1008686 wayneoi 喵！
172.16.12.5

2:37 A 好像是二分喵？
2:38 好像还要差分喵。
2:42 不对是前缀和和二分喵。
2:50 打完了喵。
2:53 大洋里全过了喵。等会打对拍喵（上午 A 挂了呜呜呜）。
3:09 这个鼠标右键怎么搞的。
3:26 B 这个建图怎么这么乱。
3:52 B 先打暴力喵。
4:10 B 暴力怎么还没调出来。
4:23 B 应该有个 44 分吧。
4:57 B 现在有个 52 分吧。
5:05 C 的 A 性质好像很好写吧。
5:29 现在大概有 162 分左右吧。
5:30 怎么办怎么办太低了太低了太低了。
1000 年了啊...... 
对啊， 
您认识的那些历史人物，变成了传奇，
您认识的那些传奇人物，变成了神话，
您认识的那些神话人物，变成了童话，
《致 1000 年后的你》 
*/

