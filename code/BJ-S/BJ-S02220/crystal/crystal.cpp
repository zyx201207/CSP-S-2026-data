#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,m;
vector<long long> a;
long long dp[500005];

//long long water(long long l,long long r){
//	long long res = 0;
//	long long top = a[r];
//	for(long long i = l;i < r;i++){
//		res += (top - a[i]);
//	}
//	return res;
//}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		long long x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	dp[1] = 0;
	long long answer = 0;
	for(long long i = 1;i < n;i++){
		dp[i] = dp[i-1] + (a[i]-a[i-1])*(i);
		//cout << "dp" << i << "=" << "dp" << i-1 << "+" << a[i] << "-" << a[i-1] << "*" << i-1 << endl;
		if(dp[i] >= m){
			answer = i;
			break;
		}	
	}
	//for(long long i = 1;i <= n;i++){
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	cout << answer << endl;
	return 0;
}