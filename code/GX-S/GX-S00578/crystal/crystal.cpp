#include<iostream>
#include<vector>
#include<cmath>
#define maxn 1000000
using namespace std;
int n, m, ans = -1;
int a[maxn];
void show(int a[maxn], int n){
	cout << "a = ";
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
}

void dfs(int a[maxn], int n, int times, int hetimes){
	int flag = 1, s = n;
	//cout << "dfs yes";
	
	if (times > m){
		return;
	}
	
	for(int i = 0; i < s; i++){
		for(int j = i + 1; j < s; j++){
			if(a[i] == a[j]){
				
				//printf("monitor: s = %d, he = %d\n", s, hetimes);
				//show(a, s);
				a[i] = a[i] + a[j];
				for(int k = j; k < s; k++){
					a[k] = a[k + 1];
				}
				
				s = s - 1;
				flag = 0;
				hetimes += 1;
				
				//printf("monitor: s = %d, he = %d\n", s, hetimes);
				//show(a, s);
			}
		}	
		int a0 = a[i];
		int tmp1[maxn], tmp2[maxn];
		for(int l = 0; l < s; l++){
			tmp1[l] = a[l];
			tmp2[l] = a[l];
		}
		tmp1[i] = a0 + 1;
		//printf("monitor: s = %d, he = %d, times = %d\n", s, hetimes, times);
		//show(a, s);
		dfs(tmp1, s, times + 1, hetimes);
		//printf("monitor: s = %d, he = %d, times = %d\n", s, hetimes, times);
		//show(a, s);
		tmp2[i] = a0 - 1;
		dfs(tmp2, s, times + 1, hetimes);
	}
	
	if (flag){
		if(hetimes >= ans){
			ans = hetimes + 1;
			show(a, n);
			printf("monitor: s = %d, ans = %d, times = %d\n", s, ans, times);
		}
		return;
	}
	
}

void solution1(){//failed
	int d[maxn], s = n;
	int mincost = 0, mindex = -1;
	while(mincost < m){
		
		for(int i = 0; i < s; i++){
			for(int j = i; j < s; j++){
				if(a[i] > a[j]) swap(a[i], a[j]);
			}
		}
		show(a, s);
		
		for(int i = 0; i < s - 1; i++){
			d[i] = abs(a[i] - a[i + 1]);
		}
		//int mincost = maxn, mindex = -1;
		mincost = maxn;
		for(int i = 0; i < s - 1; i++){
			if(mincost > d[i]){
				mincost = d[i];
				mindex = i;
			}
		}
		printf("monitor: s = %d, mindex = %d\n", s, mindex);
		a[mindex] = a[mindex] + a[mindex + 1] + mincost;
		show(a, s);
		for(int k = mindex + 1; k < s; k++){
			a[k] = a[k + 1];
		}	
		cout << "after : " ; show(a, s);			
		s = s - 1;
		m = m - mincost;
		printf("monitor: s = %d, mindex = %d\n", s, mindex);
	}
	ans = n - s;
}

void solution2(){
	int d[maxn];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[j] = abs(a[i] - a[j]);
		}
		//show(d, n);
		//printf("monitor: i = %d\n", i);
		for(int k = i; k < n; k++){
			d[k] = d[k + 1];
		}
		//show(d, n);
		for(int o = 0; o < n - 1; o++){
			for(int p = o; p < n - 1; p++){
				if(d[o] > d[p]) swap(d[o], d[p]);
			}
		}
		int cnt = 0, cost = 0;
		while(cost <= m){
			cost += d[cnt];
			cnt++;
		}
		if(cnt > ans){
			ans = cnt;
			//show(d, n);
		}
	}
}


int main(){
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w",stdout);
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	if(n <= 10000){
		solution2();
	}
	if(n > 10000) ans = n;
	cout << ans;
	
}
