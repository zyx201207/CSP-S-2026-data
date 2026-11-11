#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 5e5 + 5;
int n, m, res, a[MAXN], s[MAXN];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i <= n;i ++)a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++)s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i ++){
		int lpos = 1, rpos = i, ans = 1;
		while(lpos <= rpos){
			int mid = (lpos + rpos) >> 1ll;
			if((a[i] * (i - mid + 1) - (s[i] - s[mid - 1])) <= m)
				rpos = mid - 1, ans = i - mid + 1;
			else lpos = mid + 1;
		}
		res = max(res, ans);
	}
	printf("%lld", res);
	return 0;
} 
