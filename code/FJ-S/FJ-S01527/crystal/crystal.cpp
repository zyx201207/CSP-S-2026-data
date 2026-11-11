#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

int n,m;
int arr[500005];
int pre[500005];

bool check(int i,int p){
	if(pre[i] - pre[p - 1] >= arr[i] * (i - p + 1) - m){
		return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();m = read();
	_for(i,1,n){
		arr[i] = read();
	}
	sort(arr + 1,arr + n + 1);
	_for(i,1,n){
		pre[i] = pre[i - 1] + arr[i];
	}
	int maxn = -1; 
	_for(i,1,n){
		int l = 1,r = i;
		while(l < r){
			//cout << l << " " << r << "\n";
			int mid = (r - l >> 1) + l;
			if(check(i,mid)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		maxn = max(maxn,i - r + 1);
	}
	print(maxn);
	
	
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
