#include<bits/stdc++.h>

typedef long long ll;
inline ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f; 
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = - x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int MM = 2e6 + 1000;
ll a[MM];
ll dp[5010][5010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), T = read();
	while(T--){
		ll n = read(), d = read();
		bool flag = 0;
		ll cha;
		for(int i = 1; i <= n; i++){
			a[i] = read();
			if(i == 2)cha = a[i] - a[i - 1];
			else if(i != 1){
				if(a[i] - a[i - 1] != cha)flag = 1;
			}
			dp[i][i] = 0;
			dp[i - 1][i] = 0;
			if(i != 1 && a[i] - a[i - 1] <= d)dp[i - 1][i] = 1;
		}
		std :: sort(a + 1, a + 1 + n);
//		dp[0][1] = 1;
		if(n <= 3){
			write(0), putchar('\n'); 
			continue; 
		}
		if(flag == 0){
			ll ge = d / cha;
			ge += ge;
			if(cha * 2 > d){
				write(0), putchar('\n');
			}else{
				write(std :: max(1ll * 0, n - ge + 1)), putchar('\n'); 	
			}	
		}else{
			for(int l = 1; l <= n; l++){
				for(int r = l + 2; r <= n; r++){
					ll mmin = 1e17, cnt = 0, w = 0;
					for(int j = r - 1; j >= l; j--){
						w += a[j + 1] - a[j];
						if(w > d){
							if(a[j + 1] - a[j] > d)cnt = 0;
							break;
						}
//						std :: cout << dp[l][j] << " " << j << " " ;
//						std :: cout << l << " " << r << '\n';
						if(mmin > dp[l][j]){
							mmin = dp[l][j];
							cnt = 1;
						}else if(mmin == dp[l][j])cnt++;
					}
					if(mmin == 0)cnt = 0;
					if(w <= d)dp[l][r] = 1;
					else dp[l][r] = cnt;
				}
			}
			ll ans = 0;
			for(int l = 1; l <= n; l++){
				for(int r = l + 1; r <= n; r++){
					if(dp[l][r] == 2){
						ans++;
//						std :: cout << l << " " << r << '\n'; 
					}
				}
			}
			write(ans), putchar('\n');
		}
	}
	
	
	return 0;
}
/*
哎，说白了就是要这个路径当中，只能有一次是可以直接beng飞过去的，越过中间的点 

我的意思是，额就是，能够从这个点 直接飞到下下个点上面去

等等，好像不是很对，你别和我说长度是他在这里的飞行次数。。。

好像还真的是。。。 

好吧，这件事告诉我们，我们要先看样例。。。

是飞行次数，也就是，额，中途经过的次数，这个次数还要恰好是，嗯，？ 

不是，是最少次数恰好是2，那么既然是最少，我们肯定希望每一次都是跳的最大一步

嗯，这样子的话，就只有可能是那种，额，只跳2次

（如果说是3次的话，加设置331，那么排列就有331,313, 133这样子次数就会更多了）

那么现在再来想等差数列的情况

要是跳2次，肯定有一个是max，有一个是差点点到max，嗯？

但是这样子也很多。。。我再看看

只能是3 + 2

不能再多了，要是是3 + 1,那么可以是2 + 2，

也就是max + max - 1，然后看个书

等差数列中，我们的，额，max = d / cha（这使他能跳的最多空袭数）
然后一共条max + max - 1个，那么对应的点数是max + max

然后看这个里面有多少个连续的max + max即可 

en， ok应该对的是ok了的，那么什么时候会是0？ 

2 * cha > d的时候

——————————————————————————

好，那么现在我们来想想n^2做法

对于每一个点，他的插值不同了，我们应该怎么办》

这个时候差不同了，嗯，

要是前面都是ok的话，就是只有这一条路可以走，那么现在我们，额？

怎么判断这里有几条路呢/

要个数是min的，还要恰好有两次走法

我们能不能这样子，就是，额，dp[l][r]表示从l -- r有几种走法

那么转移式是？

r从某一个起点开始，然后跳这么多步还没有断 
 

dp[l][r] = 看dp[l][j] + 1出现的min的个数是多少个 
(从j + 1 -- r开始的值都是ok的)

嗯？但是等等，坐标不是从小到大跑的么？

那么？

等等等哈，额，我想想，这里的话，我们?

好像就只能这么做

哎哎哎，不管了，先写 

8 3
0 1 2 4 8 10 11 13

如果说，额，就是，中间有一个点是>d，那么我们也不能要，所有包含这个点的都不能要 
*/ 
