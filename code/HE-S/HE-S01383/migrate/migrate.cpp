#include<bits/stdc++.h>
#define int long long
#define Pii pair<int,int>

using namespace std;

inline int read() {
	int x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}
void out(int x) {
	if(x > 9)out(x / 10);
	putchar(x % 10 + '0');
}

const int SIZN = 2e6 + 10;
const int FLAG = LONG_LONG_MAX;

int c;
int t;
int n,d;
int a[SIZN];
int pos[SIZN];
int rpos[SIZN];
int init() {
	memset(a,0,sizeof(0));
	memset(pos,0,sizeof(pos));
	n = 0;
	d = 0;
	
	a[0] = LONG_LONG_MIN >> 1;
}
inline bool CHECK(int l,int r) {
	if(r - l + 1 - 2 >= 2) { //at least two point
		if(a[l + 2] - a[l] <= d && a[l + 3] - a[l] > d)return true;
		else return false;
	}
	return false;
}
int MAKE() {
	int i = 1,j = 1;
	while(i <= n) { //only discuss the last_pos one witch can make double_point
//		cout << i;
		if(a[i] - a[i - 1] > d) {
			pos[i - 1] = FLAG;
			i++;
			continue;
		}
		
//		cout << i << ' ';
		while(a[i] - a[j] > d){
			j++;
//			cout << j << ' ' << a[i] - a[j] << ' ';
		}
//		cout << '\n';
		j--;
		if(CHECK(j,i)){
			pos[j] = i;
			rpos[i] = j;
		}
		else {
			pos[j] = -i;
			rpos[i] = -j;
		}

//		cout << i << ' ' << j << ' ' << pos[j] << '\n';
		i++;//dont move
	}
}
int ANS(){
	int l = 1,r = 1;
	int ans = 0;
	int sums = 0;
	int p = 0,pr = 0;
	while(r <= n){
		p = pr = 0;
		while(true && r <= n){
//			cout << r;
			if(rpos[r] > 0)sums++;
			if(rpos[r] < 0)pr = -rpos[r];
			if(pos[r] < 0)p = -pos[r];
			if(pos[r] == FLAG){//mention it****
				break;
			}
			if(p && p <= r){
				r--;
				break;
			}
			
			r++;
		}
//		cout << l << ' ' << r << '\n';
		ans += (sums > 0) & (p) * 2;
		while(l <= pr)l++;
		while(l < r){
//			cout << l << ' ' << sums << "*\n";
			ans += (sums > 0);
			if(pos[l] > 0)sums--;
			l++;
		}
//		cout << '\n';
		
		
		if(pos[r] == FLAG){
			r++;
			l = r;
		}
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	need replace
 	c = read();
	t = read();
	while(t--) {
		init();

		n = read();
		d = read();
//		cout << n << d << ' ';
		for(int i = 1 ; i <= n ; i++)a[i] = read();
		
		MAKE();
		
//		for(int i = 1 ; i <= n ; i++)cout << pos[i] << ' ';
//		cout << '\n';
		out(ANS());
		putchar('\n');
	}
	return 0;
}
