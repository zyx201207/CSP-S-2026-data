#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200005;
const ll pow_2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int n, m;
int a[maxn];
int cnt[35];
int ff = -1;
int sum;
void p(int x){
	int i = 0;
	while(x){
		if(x & 1) cnt[i]++;
		x >>= 1;
		i++;
	}
}
bool find(int x, int y){
	for(int i = 30; i >= 0 && x; i--){
		if(x >= pow_2[i]){
			if(y == i) return true;
			x -= pow_2[i];
		}
	}
	return false;
}
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p(a[i]);
	}
	for(int i = 30; i >= 0; i--){
		if(cnt[i] >= m){
			ff = i;
			break;
		}
	}
	if(ff == -1){
		cout << 0;
		return 0;
	}
	bool f = 0;
	sort(a + 1, a + n + 1, cmp);
	int num = 0;
	for(int i = 1; i <= n && num < m; i++){
		if(find(a[i], ff)){
			if(f == 0) sum = a[i];
			else sum = sum & a[i];
			f = 1;
			num++;
		} 
	} 
	cout << sum;
	return 0;
}
