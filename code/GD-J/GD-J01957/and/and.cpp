#include<bits/stdc++.h>
using namespace std;
#define int long long //注意longlong内存

//多测清空
//取消fre注释
//检查格式，检查边界
//注意时空复杂度 

const int N = 2e5 + 5;
int a[N];
int bitsum[40];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);//注意不混用cin,scanf,getchar
	
	int n, m, ans = 0, pp, ta, tmpcur;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ta = a[i];
		pp = 0;
		while(ta > 0) {
			bitsum[pp] += (ta & 1);
			ta >>= 1;
			pp++;
		}
	}
	for(int p = 35; p >= 0; p--) {
		if(bitsum[p] >= m) {
			ans += 1 << p;
			tmpcur = 0;
			for(int i = 1; i <= n; i++) {
				if((a[i] >> p) & 1)
					a[++tmpcur] = a[i];
				else {
					ta = a[i];
					pp = 0;
					while(ta > 0) {
						bitsum[pp] -= (ta & 1);
						pp++;
						ta >>= 1;
					}
				}
			}
			n = tmpcur;
		}
	}
	cout << ans;
	
	return 0;
	//我去我去我去居然做出来了？？？！ 
	//Trick or Treat!
	//I_AK_IOI
}

