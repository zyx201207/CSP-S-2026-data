#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

int c,T;
int n,d;
int x[200005];
int t[200005];

void dfs(int pos,int step,int en){
	if(pos == en){
		t[step]++;
		return;
	}
	_for(i,pos + 1,n){
		if(x[i] - x[pos] <= d){
			dfs(i,step + 1,en);
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read();T = read();
	while(T--){
		memset(t,0,sizeof t);
		n = read();d = read();
		
		_for(i,1,n){
			x[i] = read();
		}
		int ans = 0;
		_for(i,1,n - 1){
			_for(j,i + 1,n){
				dfs(i,0,j);
				int l = 1;
				while(t[l] == 0) l++;
				if(t[l] == 2) ans++;
			}
		}
		print(ans - 1);
		putchar('\n');
	}
	return 0;
}

inline int read(){
	int x = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch - 48);
		ch = getchar();
	}
	return x * w;
}

inline void print(int t){
	if(t < 0){
		putchar('-');
		t = -t;
	}
	static int sta[65];
	int top = 0;
	do{
		sta[top++] = t % 10;
		t /= 10;
	}while(t);
	while(top--) putchar(sta[top] + '0');
}
