#include<bits/stdc++.h>
#define int long long
#define Pii pair<int,int>

using namespace std;

inline int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
void out(int x){
	if(x > 9)out(x / 10);
	putchar(x % 10 + '0');
}

const int SIZN = 5e5 + 10;
const int SIZM = 505;

int n,m,c,q,d;
Pii lines[SIZN][30];
int cnts[SIZN];
int dis[SIZM][SIZM];
int w[SIZN];
inline int ANS(int l,int r){
	int ans = LONG_LONG_MAX;
	for(int i = 1 ; i <= cnts[l] ; i++){
		for(int j = 1 ; j <= cnts[r] ; j++){
			int x = lines[l][i].first;
			int y = lines[r][j].first;
			int needs = 0;
			needs += lines[l][i].second;
			needs += lines[r][j].second;
			needs += dis[x][y];
//			cout << needs << ' ' << x << ' ' << y << '\n';
//			cout << lines[l][i].second << ' ' << lines[r][j].second << '\n';
			ans = min(ans,needs);
		}
	}
	return ans + w[l] + w[r];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1 ; i <= m ; i++)w[i] = read();
	for(int i = 1 ; i <= n ; i++){
		int k = read();
		for(int j = 1 ; j <= k ; j++){
			int a = read(),t = read();
			lines[a][++cnts[a]] = Pii(i,t);
		}
	}
	
	memset(dis,0x3f,sizeof(dis));//mention this place
	for(int i = 1 ; i <= n ; i++)dis[i][i] = 0;
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= cnts[i] ; j++){
			for(int k = 1 ; k <= cnts[i] ; k++){
				int x = lines[i][j].first;
				int y = lines[i][k].first;
				if(x != y)dis[x][y] = min(dis[x][y],lines[i][j].second + lines[i][k].second);
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			for(int k = 1 ; k <= n ; k++){
				if(i != j)dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	
//	for(int i = 1 ; i <= n ; i++){
//		for(int j = 1 ; j <= n ; j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for(int i = 1 ; i <= q ; i++){
		int l = read(),r = read();
		out(ANS(l,r));
		putchar('\n');
	}
	return 0;
}
