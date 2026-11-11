#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 200010

int n;
int m = 0;
long long a[N];
long long nw[N];
char nc[N];
char c[N];
int x, y, z;
char lst = '1';
string st = "";
long long ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for(int i = 1;i <= n; i++){
		char str;
		int s;
		cin >> s >> str;
		if(str == lst){
			a[m] += s;
		}else{
			m ++; 
			a[m] = s;
			c[m] = str;
		}
		lst = str;
	}
	for(int i = 1;i <= m; i++){
		for(int j = 1;j <= a[i]; j++){
			st = st + c[i];
		}
	}
	unsigned long long len = st.size();
	for(int i = 0, j = len - 1;i < j; i++, j--){
		ans += (st[i] != st[j]);
	}
	cout << ans;
	return 0;
}

