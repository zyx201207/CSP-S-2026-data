#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

int arr[200005];
int brr[200005];
char c[200005];
char d[200005];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n = read();
	int res = 0;
	int sum = 0;
	_for(i,1,n){
		arr[i] = read();
		brr[n - i +1] = arr[i];
		cin >> c[i];
		sum += arr[i];
		d[n - i + 1] = c[i];
	}
	int l = 1,r = 1;
	while(true){
		//cout << l << " " << r << " " << res <<"\n";
		if(arr[l] == brr[r]){
			if(c[l] == d[r]){
				res += arr[l];
			}
			l++;r++;
		}
		else if(arr[l] > brr[r]){
			arr[l] -= brr[r];
			if(c[l] == d[r]){
				res += brr[r];
			}
			r++;
		}
		else if(arr[l] < brr[r]){
			brr[r] -= arr[l];
			if(c[l] == d[r]){
				res += arr[l];
			}
			l++;
		}
		if(l > n || r > n){
			break;
		}
	}
	//cout << res;
	print((sum - res) / 2);
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
