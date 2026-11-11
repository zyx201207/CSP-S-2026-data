#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
//freopen
//	freopen
gdiyvxlj vxvxgd
12345678123487651234876512348765
wmdx
llsl
iwant1=
giveme1=
LG: KALEIDXSCOPE
migarte
fd vs. df
itn int

int mian();
ccf = Chinese Can Fly
*/

/*
T1写游记
15:04 T1不会 
15:09 Cryogenic全侧神曲神铺!!!
15:10 噔噔噔 噔噔 噔噔 噔噔噔噔噔噔噔
15:17 T1会了 
15:22 T1不会
15:41 T1会了 
16:38 T2Floyd快打完了 
16:45 T2打完了 
17:46 静待考试结束

17:53 发现T2代码行数跟-J T1差不多
18:05 发密码条了
18:09 可是赛百味真的不好吃
18:16 Camellia啥时候跟CCF共创一首结晶（雾
18:17 tgnb
18:18 laurnb 
18:19 karamerunb
18:20 ccfnb
18:21 t+pazolitenb
18:22 rsnb
18:23 nbrnb
18:24 abmnb
18:25 sskrnb
18:26 kkksc03cnb
18:27 chenzhenb
18:28 KALEIDXSCOPEnb
18:29 交了 
*/

int n, m;
int cry[500010];
int su1fur[500010];

bool mian(int x) {
	if (x > n)
		return false;
	
	for (int i = x; i <= n; i++) {
		int cur = cry[i] * x - su1fur[i] + su1fur[i - x];
		
		if (cur <= m)
			return true;
	}
	
	return false;
}

signed main() {
	string FILENAME = "crystal";
	string IFILE = FILENAME + ".in";
	string OFILE = FILENAME + ".out";
	freopen(IFILE.c_str(), "r", stdin);
	freopen(OFILE.c_str(), "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> cry[i];
		su1fur[i] = su1fur[i - 1] + cry[i];
	}
	
	sort(cry + 1, cry + n + 1);
	
	for (int i = 1; i <= n; i++) {
		su1fur[i] = su1fur[i - 1] + cry[i];
	}
	
	int L = 1, R = n + 1;
	
	while (L + 1 < R) {
		int mid = (L + R) / 2;
		
		if (mian(mid))
			L = mid;
		else
			R = mid;
	}
	
	cout << L;
}

