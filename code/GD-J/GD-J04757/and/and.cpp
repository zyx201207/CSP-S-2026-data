#include<bits/stdc++.h>
using namespace std;
int n, m, maxn, len[200003];
struct node{
	long long a, b;
}h[200003];
long long t[35];
int f(int x){
	long long cnt = 0;
	for(int i = maxn; i >= 0; i--){
		if(t[i] > x){
			cnt += t[i];
		}else{
			x -= t[i];
		}
	}
	return cnt;
}
bool cmp(node x, node y){
	if(x.b > y.b){
		return false;
	}else if(x.b == y.b){
		if(x.a > y.a){
			return true;
		}else{
			return false;
		}
	}else{
		return true;
	}
}
int g(int x){
	int k = 0, sum = 1;
	while(x > sum){
		k++;
		sum += t[k];
	}
	return k;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	t[0] = 1;
	for(int i = 1; i <= 34; i++){
		t[i] = 2 * t[i - 1];
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> h[i].a;
		len[i] = g(h[i].a);
		maxn = max(maxn, len[i]);
	}
	for(int i = maxn; i >= 0; i = maxn){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(len[i] >= maxn){
				cnt++;
			}
		}
		if(cnt >= m){
			break;
		}else{
			maxn--;
		}
		for(int i = 1; i <= n; i++){
			if(len[i] > maxn){
				for(int j = len[i]; j > maxn; j--){
					h[i].a -= t[j];
				}
				while(t[len[i]] > h[i].a) len[i]--;
			}
		}
	}	
	for(int i = 1; i <= n; i++){
		h[i].b = f(h[i].a);
	}
	sort(h + 1, h + n + 1, cmp);
	for(int i = 2; i <= m; i++){
		h[1].a = (h[1].a & h[i].a);
	}
	cout << h[1].a;
	return 0;
}

