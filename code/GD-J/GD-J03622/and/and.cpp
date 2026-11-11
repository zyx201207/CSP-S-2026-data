#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

#define N 200010
#define K 40

int n, m;
int sum[K];
int s0;
long long ans;

struct stu{
	int a;
	int w[K];
	int s = 0;
	int ws = 0;
}a[N];

bool cmp(stu x, stu y){
	
	if(x.ws != y.ws)return x.ws > y.ws;
	else if(x.s != y.s)return x.s > y.s;
	else return x.a > y.a;
}

void get(int ii,int x){
	int i = 0;
	while(x){
		a[ii].w[++i] = (x & 1);
		a[ii].s += (x & 1);
		x >>= 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i].a;
		if(a[i].a == 0){
			s0++;
			continue;
		}
		get(i, a[i].a);
	}
	if(n - s0 < m){
		cout << 0;
		return 0;
	}
	n -= s0;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j < K; j++){
			if(a[i].w[j] == 1)a[i].ws += sum[j];
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	ans = a[1].a;
	for(int i = 2;i <= m; i++){
		ans = ans & a[i].a;
	}
	cout << ans;
	return 0;
}

