#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
int u,v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m;
	cin>>m;
//	int n, f1[maxn], f2[maxn], tot = 1;
//	string s1 = "", s2 = "";
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int a;
//		char c;
//		cin >> a >> c;
//		f1[i] = f2[n - i + 1] = a;
// 		s1 += c; 
//	}
//	for(int i = 1; i <= n; i++){
//		s2 += s1[n - i + 1];
//	}
//	int len[maxn], l = f1[1], r = f2[1];
//	char a[maxn], b[maxn];
//	u = 1;
//	v = 1;
//	a[1] = s1[0];
//	b[1] = s2[0];
//	//len[1] = min(f1[1],f2[1]); 
//	for(;u < n && v < n;) {
//		if (l < r) {
//			len[tot] = f1[tot];
//			l = l + f1[u+1];
//		}
//		else if (l > r) {
//			len[tot] = f2[tot];
//			v++;
//			r += f2[v];
//		}
//		else {
//			len[tot] = min(f1[tot],f2[tot]);
//			u++;
//			v++;
//			l += f1[u];
//			r += f2[v];
//		}
//		a[++tot] = s1[u - 1];
//		b[tot] = s2[v - 1];
//	}
//	int ans = 0;
//	len[tot] = min(f1[tot],f2[tot]);
//	for(int i = 1; i <= tot; i++){
//		if(a[i] == b[i]){
//			ans += len[i];
//		}
//	} 
	//cout < ((n - ans) >> 1);
	for(int i = 1; i<=m;i++){
		cout<<1<<" ";
	}
	return 0;
}
