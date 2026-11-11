#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w; 
}
const int MAXN = 5e5 + 8; 
int n,m,a[MAXN],s[MAXN],ans = 0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();m = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		int L = 1,R = i,j = i + 1;
		while(L <= R){
			int mid = (L + R) >> 1;
			if(a[i] * (i - mid) - s[i - 1] + s[mid - 1] <= m){
				R = mid - 1;
				j = mid;
			}
			else L = mid + 1;
		}
		if(a[i] * (i - j) - s[i - 1] + s[j - 1] <= m) ans = max(ans,i - j + 1); 
	} 
	cout << ans << "\n";
	return 0; 
} 
