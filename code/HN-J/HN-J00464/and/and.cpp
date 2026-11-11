#include <bits/stdc++.h>
using namespace std;

// 想不出来了...
// RP++
// 
// 好无聊 (11:11) 
// dayz的time表太牢了 
// dayz class 850 的 ywb 和 js 是 (char)70 (char)101 (char)109 (char)98 (char)97 (char)121.
//  
// 随意打字区： 
// I use archlinux, btw
// KISS
// 当把 sudo rm -rf ./* 打成 sudo rm -rf /* 时:
// User: NO!!!!! Linux: Bye! 
// neko
// deepseek
// Nodejs Go TypeScript Java C++ Python Rust Lua C# C PHP 
// Minecraft is the best game
// My blog: Astro + Gin
// Area Breakout 117
// 十年oi一场空，不开longlong见祖宗 
// 蒟蒻 
// luogu, leetcode, atcoder
// today感觉j组考得比较 nice 
// OIer ACMer ICPCer
// NVIDIA AMD INTEL
// 什么时候DDR5内存能降下来 qwq
// Minecraft还是太吃内存了 
// DP还是太吃操作了
// 理想配置:
// NVIDIA RTX5090 32G  AMD Ryzen9 9950X3D  DDR5 6000mt/s 48G*4 

typedef long long ll;
const ll N = 2*1e5+5;
ll n, m, a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	cout << a[time(0)%n] << "\n"; // 听天意 hhh

	return 0;
}

