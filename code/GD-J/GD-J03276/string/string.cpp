// 使用大量 cerr 时，务必使用 steady_clock 等工具计时，注释应该不占用太多时间吧 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
vector<pair<int, pair<int, char>>> s1, s2;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	s1.resize(n + 5), s2.resize(n + 5);
	for (int i = 1; i <= n; i++){
		s1[i].fir = i;
		cin >> s1[i].sec.fir >> s1[i].sec.sec;
		s2[n - i + 1].fir = i;
		s2[n - i + 1].sec.fir = s1[i].sec.fir;
		s2[n - i + 1].sec.sec = s1[i].sec.sec;
	}
//	for (int i = 1; i <= n; i++){
//		cerr << s1[i].fir << " " << s1[i].sec.fir << " " << s1[i].sec.sec << "    ";
//		cerr << s2[i].fir << " " << s2[i].sec.fir << " " << s2[i].sec.sec << "    ";
//		cerr << endl;
//	}
	
	int l1 = s1[1].sec.fir, l2 = s2[1].sec.fir, ans = 0, cnt = 0, forcnt = 0;
	for (int i1 = 1, i2 = 1; s1[i1].fir <= s2[i2].fir; ){
		forcnt++; 
		if(l1 <= l2){
			if(s1[i1].sec.sec != s2[i2].sec.sec){
				ans += l1;
				cnt++;
//				cerr << "ans += " << l1 << '\n';
			}
			l2 -= l1, l1 = 0;
		}else if(l1 > l2){
			if(s1[i1].sec.sec != s2[i2].sec.sec){
				ans += l2;
				cnt++;
//				cerr << "ans += " << l2 << '\n';
			}
			l1 -= l2, l2 = 0;
		}
		if(l1 == 0){
			l1 = s1[++i1].sec.fir;
		}
		if(l2 == 0){
			l2 = s2[++i2].sec.fir;
		}
	}
	cout << ans << '\n';
	return 0;
}
