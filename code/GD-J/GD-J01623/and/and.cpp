#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 20;
char buf[M];
int len, pos;
inline int gc(){
	if(len == pos){
		pos = 0;
		len = fread(buf, 1, M, stdin);
		if(len == 0) return EOF;
	}
	return buf[pos++];
}
inline int read(){
	int s(0), t(1), c = gc();
	for(;c != EOF && (c < '0' || c > '9');c = gc()) if(c == '-') t = -1;
	if(c == EOF) return 0;
	for(;c >= '0' && c <= '9';c = gc()) s = (s << 3)+(s << 1)+(c ^ 48);
	return s*t;
}
int a[1000005];
vector <int> w[50];
bool b[200005][35], vis[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n = read(), m = read(), ans(0);
	for(int i = 1, d;i <= n;i++){
		d = a[i] = read();	
		vis[i] = true;
		for(int j = 0;j <= 30 && d > 0;j++, d = (d >> 1)){
			b[i][j] = d % 2;
			if(b[i][j] == true)
				w[j].push_back(i);			
		}
	}
	
	for(int i = 30;i >= 0;i--){
		int cnt(0);
		for(int j = 0;j < w[i].size();j++)
			if(vis[w[i][j]] == true)
				cnt++;
		if(cnt >= m){
			ans += (1 << i);
			for(int k = 1;k <= n;k++)
				vis[k] = (vis[k] & b[k][i]);
		}
	}
	cout << ans;
}
