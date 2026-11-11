#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5*1e5 + 7;
long long n, m;
long long a[N], sum[N];//sum[i]表示第i个数到达最后一个数的代价 
long long sum2[N];//表示正常差值 
bool cmp(long long a, long long b){
	return a < b;
} 
bool check(int x){
//	cout << "x = " << x << endl;
	long long ok = 0x3f3f3f3f; 
	for(int i = 1; i <= n-x+1; i++){
		ok = min(ok, sum[i] - sum[i + x - 1] - (x - 1) * (a[n] - a[i + x - 1]));
//		cout << i << " " << i + x - 1 << "  " << sum[i] - sum[i + x - 1] - (x - 1) * (a[n] - a[i + x - 1]) << endl;
//		cout << "sum[i] = " << sum[i] << "  sum[i+x-1]=" << sum[i+x-1] << "  (x - 1)*(a[n]-a[i + x - 1])= " << (x - 1)*(a[n] - a[i + x - 1])<<endl;
	}
//	cout << endl;
//	cout << "ok= " << ok << "m= " << m << endl;
	if(ok <= m)return true;
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	sum[n] = 0;
	for(int i = n - 1; i >= 1; i--){
		sum[i] = a[n] - a[i] + sum[i + 1];
	}/*
	for(int i = n; i >= 1; i--){
		cout << sum[i] << endl;
	}*/
//	cout << endl << endl;
	int L = 1, R = n, mid = 0;
	while(L <= R){
//		cout << "L= "<<L << " R= " << R << endl;
		mid = (L + R) >> 1;
		if(check(mid)){//可行向右 
			L = mid + 1;
		}else{
			R = mid - 1;
		}
	}
	cout << R;
	return 0;
} 
/*二分答案，最小为1个，最大为n个 
check：因为只能增加，所以判断从小到大
因此先排序，然后选取其中一段长度为mid的区间
作为当前合并的区间，代价就是每个数与最大值的差，
看是否小于m 
6 6
1 6 13 14 17 19
*/ 
