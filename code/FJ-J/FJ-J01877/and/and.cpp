#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

int n,m;
int arr[200005];

bool vis[200005];
int ans = -1;
void dfs(int op,int k,int v){
	if(vis[op]) return;
	if(k == m){
		ans = max(ans,v);
		return;
	}
	k++;
	v &= arr[op];
	_for(i,1,n){
		vis[op] = true;
		dfs(i,k,v);
		vis[op] = false;
	}
} 

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read();
	m = read();
	int mm = (1 << 30) - 1;
	bool fl = true;
	_for(i,1,n){
		arr[i] = read();
		bool fla = false;
		_for(j,0,30){
			if((1 << j) - 1 == arr[i]){
				fla = true;
				break;
			}
		} 
		fl = fla && fl;
		mm &= arr[i];
	}
	if(m == n){
		print(mm);
		return 0;
	}
	if(n <= 20){
		_for(i,1,n){
			dfs(i,0,(1 << 30) - 1);
		}
		print(ans);
		return 0;
	}
	if(m == 1){
		sort(arr + 1,arr + n + 1);
		print(arr[n]);
		return 0;
	}
	if(fl){
		sort(arr +1,arr + n + 1);
		print(arr[n - m +1]);
		return 0;
	}
	if(m == 2){
		_for(i,1,n){
			_for(j,1,n){
				if(i != j){
					ans = max(ans,arr[i] & arr[j]);
				}
			}
		}
		print(ans);
		return 0;
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
		x = (x << 1) + (x << 3) + (ch - 48);
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
	while(top--) putchar(sta[top] +'0');
}
