#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

int n,m;
int arr[500005];
vector<int> vis[300005];
bool vs[300005];
int ans[300005];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n = read();m = read();
	_for(i,1,n){
		arr[i] = read();
		vis[arr[i]].push_back(i);
	}
	_for(i,1,m){
		if(vis[i].size() > 1){
			vs[i] = true;
		}
	}
	_for(i,1,n){
		
		int j = i;
		while(j <= n){
			ans[arr[j]]++;
			_for(k,0,vis[arr[j]].size() - 1){
				if(vis[arr[j]][k] == j){
					j = vis[arr[j]][vis[arr[j]].size() - 1];
					break;
				}
			}
			j++;	
		}
	}
	_for(i,1,m){
		print(ans[i]);
		putchar(' ');
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

//RP++
