#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 2e5 + 10;
struct node{
	LL num;
	char c;
} a[N];
int n;
LL ans, cnt;
map<int, char> s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n >> a[1].num >> a[1].c;
	cnt = a[1].num;
	for(int i = 2; i <= n; i++){
		cin >> a[i].num >> a[i].c;
		cnt = __gcd(cnt, a[i].num);
	}
	int pos = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i].num / cnt; j++) s[++pos] = a[i].c; 
	}
	for(int i = 1; i <= pos/ 2; i++){
		if(s[i] != s[pos - i + 1]){
			ans++;
		}
	}
	cout << ans * cnt;
	return 0;
}
