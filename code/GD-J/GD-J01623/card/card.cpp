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

int n, m, k;
int a[500005];
int b[500005];
bool vis[500005];


int d[500005];
int w[500005];
int ans[500005];

int lowbit(int x){
	return x & (-x);
}

void add(int x, int val){
	for(int i = x;i <= n;i += lowbit(i))
		a[i] += val;
}

void cl(int x){
	for(int i = x+1;i <= n;i++)
		d[i] = a[i] = 0;
}

int getsum(int x){
	int sum(0);
	for(int i = x;i >= 1;i -= lowbit(i))
		sum += a[i];
	return sum;
} 

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i <= n;i++)
		b[i] = read();
	for(int i = 1, t;i <= n;i++){
		t = b[n-i+1]; add(1, 1);
		if(vis[t] == false){
			vis[t] = true;
			d[++k] = t; w[t] = k;
			add(k+1, -1);
		}
		else{
			add(w[t]+1, -1);
			for(int j = w[t]+1;j <= k;j++){
				ans[d[j]] += getsum(j);	
				vis[d[j]] = false;			
			}
			cl(w[t]); k = w[t];
		}
	}
	for(int i = 1;i <= k;i++)
		ans[d[i]] += getsum(i);
	for(int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
}
