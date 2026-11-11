#include<iostream>
using namespace std;
const int N = 100001;
struct E{
	int len;
	char c;
};
int min(int a, int b){
	if(a > b)return b;
	else return a;
}
E a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	char c;int k;long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> k >> c;
		a[i].len = k;
		a[i].c = c;
		sum += k;
	}
	sum /= 2;
	long long lsum = 0, rsum = 0, cnt = 0;
	long long l_id = -1, r_id = n;
	while(rsum <= sum && lsum <= sum){
		if(lsum > rsum){
			if(a[l_id].c != a[r_id].c)cnt += (lsum - rsum);
			r_id--;rsum += a[r_id].len;
		}else if(lsum < rsum){
			if(a[l_id].c != a[r_id].c)cnt += (rsum - lsum);
			l_id++;lsum += a[l_id].len;
		}else{
			l_id++;lsum += a[l_id].len;
			r_id--;rsum += a[r_id].len;
			if(a[l_id].c != a[r_id].c)cnt += min(a[l_id].len, a[r_id].len);
//			cout << 1 << endl;
		}
	}
//	cout << sum << " " << lsum << " " << rsum << endl;
	if(rsum < sum || lsum < sum){
		cnt += 2 * sum - lsum - rsum;
	}
	cout << cnt << endl;
	return 0;
}
