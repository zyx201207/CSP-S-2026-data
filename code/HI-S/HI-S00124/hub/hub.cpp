#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int read() {
	int x=0,f=1;char chr=getchar();
	while (chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while ('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
}
const int N = 1e6 + 10;
int ver[2 * N],nxt[2 * N],head[N],tot = 0;
void add(int x,int y) {
	ver[++tot] = y,nxt[tot] = head[x],head[x] = tot;
}
int c,T;
int n,m;
int q[N],l = 1,r = 0;
int d[N],fa[N];
int bfs(int s) {
	l = 1,r = 0;
	memset(d + 1,0,n * sizeof(int));
	q[++r] = s;
	d[s] = 1;
	fa[s] = 0;
	while (l <= r) {
		int x = q[l++];
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			fa[y] = x;
			q[++r] = y;
		}
	}
	return q[r];
}
ostream& operator<<(ostream &os,const vector<int> &v) {
	os << "{";
	for (int i = 0; i < v.size(); i++) {
		os << v[i];
		if (i == v.size() - 1) {
			os << "}";
		}
		else {
			os << ",";
		}
	}
	return os;
}
vector<int> path; // 直径 
int s,t;
int mx[N];
void dfs(int x,int id) {
	mx[id] = max(mx[id],d[x]);
//	cout << "x = " << x << " id = "<<id << " d[x] = "<<d[x] <<"\n";
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (d[x] > d[y]) continue;
		dfs(y,id);
	}
}
int b[N];
bool check(int mid) {
//	cout << "mid = " << mid << "\n";
	int need = 0;
	for (int i = mid + 1; i <= path.size() - mid - 2; i++) {
		if (mid < mx[i]) {
			need += mx[i] - mid;
		}
	}
//	cout << "m = " << m  << " need = " << need << "\n";
	if (0 > m - 2 - need) return false;
	for (int i = 0; i <= m - 2 - need + 1; i++) {
		b[i] = 0;
	}
	for (int i = mid + 1; i <= path.size() - mid - 2; i++) {
		int len1 = min(mid,mx[i]) + i - mid,len2 = path.size() - mid - 1 - i + min(mid,mx[i]);
//		cout << "i = " << i << " mx[i] = "<<mx[i] << " len1 = " << len1 <<" len2 = "<<len2<<"\n";
		if (len1 <= mid || len2 <= mid) {
			continue;
		}
		int nr = len1 - mid - 1,nl = m - 2 - need - (len2 - mid) + 1; // 不合法的区间 
		nl = max(nl,0),nr = min(nr,m - 2 - need);
		if (nl > nr) continue;
		b[nl]++,b[nr + 1]--;
//		cout << "nl = " << nl <<" nr = "<<nr<<"\n";
	}
	if (b[0] == 0) return true;
	for (int i = 1; i <= m - 2 - need; i++) {
		b[i] += b[i - 1];
		if (b[i] == 0) {
//			cout << "i = " << i << "\n"; 
			return true;
		}
	}
	return false;
}
int solve() {
	n = read(),m = read();
	memset(head + 1,0,n * sizeof(int)),tot = 0;
	for (int i = 1; i < n; i++) {
		int x = read(),y = read();
		add(x,y),add(y,x);
	}
	if (n == m) return 0;
	s = bfs(1),t = bfs(s);
//	cout << "s = " << s << " t = " << t << "\n";
	path.clear();
	int x = t;
	do {
		path.push_back(x);
		x = fa[x];
	} while (x);
//	cout << "path = " << path << "\n";
	for (int i = 1; i + 1 < path.size(); i++) {
		mx[i] = d[path[i]];
		for (int j = head[path[i]]; j; j = nxt[j]) {
			int x = ver[j];
			if (x == path[i - 1] || x == path[i + 1]) continue;
			dfs(x,i);
		}
		mx[i] -= d[path[i]];
	}
//	cout << "mx = ";for (int i = 1; i + 1 < path.size(); i++) cout << mx[i] << " ";cout << "\n";
	int l = 1,r = (path.size() - 1) / 2;
//	cout << "l = " << l << " r = " << r <<"\n";
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
//	cout << "l = " << l << " r = " << r <<"\n";
	return l;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),T = read();
	while (T--) {
		cout << solve() << "\n";
	}
	return 0;
}
