#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long sum[500005];
int ans;

void binary(int p, int end, int nd){
	
	if(p < 1 || p > end) return;
	if(nd < 0) return;
	
	//枚举右端点，二分左端点
	//p为左端点下标，end为右端点下标 
	//end - p + 1为长度，sum[end] - sum[p-1]为区间和
	//若长度*末尾<=区间和+m，则区间合法，向左继续查找 
	//否则，区间非法，向右继续查找
	
	int len = end - p + 1;
	long long qsum = sum[end] - sum[p - 1];
	
	int d = ceil((nd + 1) / 2.0) - 1;
	if(nd == 0) d = -1;
	
	if(len * a[end] <= qsum + m){
		//区间合法
		ans = max(ans, len);
		binary(p - nd, end, d);
		
	}
	else{
		//区间非法 
		binary(p + nd, end, d);
		
	}
	
	
	
	
}

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	 
	
	for(int i = 1; i <= n; i++){
		sum[i] = a[i] + sum[i - 1];
	}
	
	
	
	for(int i = 1; i <= n; i++){
		binary(1, i, ceil(i / 2.0) - 1);
	}
	
	cout << ans;
	
	
	return 0;
} 
