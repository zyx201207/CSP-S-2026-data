#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 2e5 + 10;

LL n, ans = 0;
LL a[MAXN];
char c[MAXN];
LL cnt[MAXN][27];
LL acc[MAXN];

LL Bsearch(LL x){//allows equal
	LL l = 0, r = n - 1;
	while(l < r){
		LL mid = (l + r + 1) / 2;
		if(acc[mid] > x)r = mid - 1;
		else l = mid;
	}
	return l;
}


int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 0; j < 26; j++){
			cnt[i][j] = cnt[i - 1][j];
		}
		cnt[i][c[i] - 'a'] += a[i];
		acc[i] = acc[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n; i++){
		LL lft = acc[n] - acc[i] + 1, rgt = acc[n] - acc[i - 1];
		LL k = Bsearch(lft), p = Bsearch(rgt);
		if(acc[p] <= acc[i])break;//fully overlapped
		
		
		LL chk = c[i] - 'a';
		LL res = cnt[p][chk] - cnt[k + 1][chk];
		if(c[k + 1] - 'a' == chk)res += acc[k + 1] - lft;
		if(c[p + 1] - 'a' == chk)res += rgt - acc[p];
		//check concidence
		ans += (rgt - lft + 1) - res;
	}
	cout << ans << '\n';
	
	
	return 0;
}

