#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a[N], sum[N], nd[N];
vector<ll> v;
stack<ll> s;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w",stdout);
	cin.tie(0) -> sync_with_stdio(false);
	int n; ll m; cin >> n >> m;
	ll ans = 1; ll p = 0;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
	for(int i = 2; i <= n; i++)if(a[i] - a[i - 1] <= m)a[i] = 0;	
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			p++;
			continue;
		}
		nd = a[i] * (i - p) - sum[i];
	}
	for(int i = n; i >= 1; i--){
		if(m >= nd[i]){
			cout << i;
			return 0;
		}
	}
	return 0;	 
}
/*


11mins:
我咋配置这么慢，开 T1。 
36mins:
会赢吗，不想退役 QAQ 这前缀和模拟起来真舒服 ， 这会 lyx喵喵 应该已经在写 T2 了吧 。 
40mins: 
我去了，这是个啥玩意啊，前缀和似乎不对喵，到底是前缀和还是二分啊啊啊啊(不会都不是吧，别骂窝唐) CCF 你真棒^_^ 
1.5h:
我了豆，二分的话是 nlogV 吧，真能过吗，唉算了试试吧，万一过了呢 OwO 开始重构！
2h:
重构失败，只能打部分分了 
2.5h:
呜呜，真的要退役了，只会一个假做法，算了，看剩下的时间能不能写点暴力吧 
3h:
哦，他是不是让我维护差值小的数尽可能多，我嘞个豆，那我前面想的岂不是错的七七八八了,但是怎么维护呢。。。 
18:27
再见啦，要爆零了 ,可能我不是学这个的料吧 
*/

 
