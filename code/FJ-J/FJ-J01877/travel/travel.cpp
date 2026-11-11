#include<bits/stdc++.h>
#define int long long
#define _for(i,a,b) for(int i = (a);i <= (b);i++)

using namespace std;

inline int read();
inline void print(int t);

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000";
		return 0;
	}
	cout << 1;
	int x = b[2] - 'A',y = d[2] - 'A';
	if(b[0] == d[0] && b[1] == d[1]){
		cout <<1;
	}else{
		cout << "000";
		return 0;
	}
	if((x <= 2 && y <= 2) || (x >= 3 && y >= 3)){
		cout << 1;
	} 
	else{
		cout << "00";
		return 0; 
	} 
	if(abs(x - y) == 1){
		cout << 1;
	}
	else cout << 0;
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
