#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(ll x){
	cin >> x;
	return;
}
ll n, m, a[1000000], ans;
bool check(ll qwq){
	ll now = 0;
	for(int i = 1; i <= qwq; i++){
		now += a[qwq] - a[i];
	}
	if(now <= m){
		return true;
	}
	for(int i = qwq + 1; i <= n; i++){
		now -= a[i - 1] - a[i - qwq];
		now += qwq * (a[i] - a[i - 1]);
		if(now <= m){
			return true;
		}
	}
	return false;
}
ll bs(ll qwq, ll pwp){
	if(qwq == pwp){
		return qwq;
	}
	ll mid = (qwq + pwp + 1) / 2;
	if(check(mid)){
		return bs(mid, pwp);
	}
	else{
		return bs(qwq, mid - 1);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	cout << bs(1, n) << endl;
	return (0 - 0);
}
//按照习俗，我应该在这里记录一下自己的游记。
//14:29 开始阅卷。秒了T1？ 
//14:35 怎么好像口胡了T2？？？ 
//14:35 阅卷呢怎么键盘声这么大。诶怎么开始了？？？ 为啥感觉T1T2都好简单的样子啊？？？ 
//14:36 键盘有点卡。 
//14:42 键盘非常卡。 
//14:43 缺省源CE了。 
//14:45 怎么大样例挂了？？ 
//14:48 原来是我笨蛋了。然后怎么又炸了？？ 
//14:51 我做法是不是假的来着，这期拉完了。 
//14:53 go to learn binary search. 给个黄吧。 
//15:02 在约30min内通过了所有大样例。不对拍了。 
//15:40 我freopen怎么注释了，还好有检查。 
