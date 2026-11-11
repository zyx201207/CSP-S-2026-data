#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 2e5 + 3;
int n, a[N];
char c[N];
string s;
int len, ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= a[i];++j){
			s += c[i];
		}
	}
	len = s.size();
	for(int i = 0, j = len-1;i < j;++i, --j){
		ans += (s[i] != s[j]);
	}
	cout << ans;
	return 0;
}
