#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans, pos, cnt;
int a[200005];
bool vis[200005];
int b[200005];

int ch(int d, int z){
	int m = 1;
	for (int i = 1; i <= z; i ++){
		m *= d;
	}
	return m;
}

string ten_two(int d){
	int c[65], x = 0, y = 0; 
	string s;
	while(d >= 1) {
		c[++ x] = d % 2;
		d = (d - c[x]) / 2;
	}
	for (int i = x; i >= 1; i --){
		s[x - i + 1] = c[i];
	}
	return s;
}

int two_ten(string s){
	int i = 0, sum = 0;
	int d = s.size(); 
	while (d){
		int u = s[d] - '0';
		sum = sum * 10 + u;
		d --;
	}
	return sum;
}

int compare(int a, int b){
	string s1 = ten_two(a);
	string s2 = ten_two(b);
	string s3;
	int sizz = max(s1.size(), s2.size());
	for (int i = 0;i <= sizz; i ++) s3[i] = 0;
	int sizs = min(s1.size(), s2.size());
	for (int i = szis; i >= 1; i --){
		if (s1[i] == s2[i]) s3[i] = 1;
	}
	return two_ten(s3);
}

void dfs(int k){
	if (k > m){
		for (int i = 2; i <= m; i ++){
			pos = compare(ten_two(b[i]) , ten_two(b[i - 1]) );
			cnt = two_ten(pos);
 		}
 		ans = max(ans, cnt);
 		return;
	}
	for (int i = 1; i <= n; i ++){
		if (!vis[i]){
			vis[i] = 1;
			b[k] = a[i];
			dfs(++ k);
			vis[i] = 0;
			b[k] = 0;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs(1);
	cout << 0;
	return 0;
}

