#include <bits/stdc++.h>
using namespace std;
long long n, m;
char s[100005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    long long now = 0; 
    for(int i = 1;i <= n;i++){
		long long c;
		cin >> c;
		char z;
		cin >> z;
		for(long long j = now;j <= c+now;j++) s[j] = z;
		now += c;
	}
	long long cnt = 0;
	long long len = now/2;
	for(long long i = 0;i <= len;i++){
		if(s[i] != s[now]){
			cnt++;
		}
		now--;
	}
	cout << cnt;
    return 0;
}