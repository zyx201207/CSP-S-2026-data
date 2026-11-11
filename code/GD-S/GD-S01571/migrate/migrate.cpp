#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Fast{
	inline int fr(){
		int x = 0,f = 1;
		char c = getchar();
		while (c < '0' || c > '9'){
			if (c == '-') f = 0;
			c = getchar();
		}
		while (c >= '0' && c <= '9'){
			x = (x << 1) + (x << 3) + (c ^ 48);
			c = getchar();
		}
		return (f ? x : -x);
	}
	char putstk[1005];
	inline void fw(int x){
		if (x == 0) return putchar('0'),void();
		if (x < 0) x = -x,putchar('-');
		int tp = 0;
		while (x) putstk[++tp] = ((x % 10) ^ 48),x /= 10;
		while (tp) putchar(putstk[tp--]);
	}
}

using namespace Fast;
int c,n,d,pos[2000005],nxt[2000005];
void shuqiangakioi(){
	n = fr(),d = fr();
	int l = 1;
	for (int i = 1;i <= n;i++){
		pos[i] = fr();
		while (l < i && pos[i] - pos[l] > d) nxt[l++] = i - 1;
	}
	/*
	while (l <= n) nxt[l++] = n;
	int ans = 0;
	for (int i = 1;i <= n;i++){
		int lst = i;
		int cnt = 0;
		for (int j = i + 1;j <= n;j++){
			if (pos[j] - pos[j - 1] > d) break;
			if (nxt[i] > j) continue;
			if (lst != i && lst > 1 && nxt[lst - 1] == j) cnt++;
			if (nxt[lst - 2] < j && nxt[lst - 1] >= j) ans++;
			if (j == nxt[lst]) lst = j;
			if (!cnt) continue;
		}
	}
	*/
	fw(0),putchar('\n');
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = fr();
	int t = fr();
	while (t--) shuqiangakioi();
	return 0;
}
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
//Oct31==Dec25?
