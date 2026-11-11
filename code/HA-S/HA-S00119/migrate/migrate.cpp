

#include <cstdio>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2000010;

int c;
int t;
int n;
long long d;
long long nums[N];
long long must[2][N];
deque<int> dq;
long long sum;
long long dp[2][N];
//vector<long long> magic;
long long res;

void wrong_solve () {
	must[0][1] = 1;
	for (int i = 2; i <= n; i++) {
		must[0][i] = 1;
		if (nums[i] - nums[i - 1] <= d) {
			if (i == n || nums[i + 1] - nums[i - 1] > d) {
				must[0][i] += must[0][i - 1];
			}
		}
	}
		
	must[1][n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		must[1][i] = 1;
		if (nums[i + 1] - nums[i] <= d) {
			if (i == 1 || nums[i + 1] - nums[i - 1] > d) {
				must[1][i] += must[1][i + 1];
			}
		}
	}
		
	dq.clear();
	sum = 0;
	for (int i = 3; i <= n; i++) {
		if (i == n || nums[i + 1] - nums[i - 2] > d) {
			sum += must[0][i - 2];
			dq.push_back(i - 2);
		}
		while (!dq.empty() && nums[i] - nums[dq.front()] > d) {
			sum -= must[0][dq.front()];
			dq.pop_front();
		}
		dp[0][i] = sum;
	}
	dq.clear();
	sum = 0;
	for (int i = n - 2; i >= 1; i--) {
		if (i == 1 || nums[i + 2] - nums[i - 1] > d) {
			sum += must[1][i + 2];
			dq.push_back(i + 2);
		}
		while (!dq.empty() && nums[dq.front()] - nums[i] > d) {
			sum -= must[1][dq.front()];
			dq.pop_front();
		}
		dp[1][i] = sum;
	}
	
	res = 0;
	for (int i = 2; i + 2 <= n; i++) {
		res += (dp[1][i - 1] * dp[0][i + 2]);
	}
}

const int Small_N = 10;

int all_u;
int all_v;
int road_cc[Small_N][Small_N];
int road_min[Small_N][Small_N];

void dfs (int u, int now_dis) {
	if (now_dis > road_min[all_u][all_v]) {
		return;
	}
	if (u == all_v) {
		if (now_dis < road_min[all_u][all_v]) {
			road_min[all_u][all_v] = now_dis;
			road_cc[all_u][all_v] = 0;
		}
		road_cc[all_u][all_v]++;
		return;
	}
	for (int v = u + 1; v <= all_v; v++) {
		if (nums[v] - nums[u] <= d) {
			dfs (v, now_dis + 1);
		}
		else {
			return;
		}
	}
}

void small_solve () {
	for (int i = 1; i <= n; i++) {
		all_u = i;
		for (int j = i + 1; j <= n; j++) {
			all_v = j;
			road_min[i][j] = 1e9;
			road_cc[i][j] = 0;
			dfs (i, 0);
			if (road_cc[i][j] == 2) {
				res++;
			}
		}
	}
}

void a_solve () {
	long long dis = nums[2] - nums[1];
	if (d < dis) {
		res = 0;
		return;
	}
	
	long long dd = d / dis;
	if (dd >= n - 1) {
		res = 0;
		return;
	}
	if (dd == 1) {
		res = 0;
		return;
	}
	res = n - dd - dd + 1;
}

int main () {
	
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	scanf ("%d%d", &c, &t);
	for (int index = 1; index <= t; index++) {
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf ("%lld", &(nums[i]));
		}
		res = 0;
		
		if (n <= 9) {
			small_solve ();
		}
		else if (c == 11 || c == 12) {
			a_solve ();
		}
		else {
			wrong_solve ();
		}
		
		printf ("%lld\n", res);
	}
	
	return 0;
}