#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	long long n,m;
	cin >> n >> m;
//	cout << n;
	long long a[n];
	for (long long i = 0;i < n;i ++ ){
		cin >> a[i];
//		cout << i;
	}	
	for (long long i = 0;i < n;i ++ ){
		cout << a[i];
	}
	long long _[m] = {0};
	for (long long i = 0;i < n;i ++ ){
		vector <long long> b;
		for (long long j = i;j < n;j ++ ){
			bool _ = 0;
			int x;
			for(long long k = 0;k < j;k ++ ){
				if (b[k] == a[j]){
					_ = 1;
					x = k;
				}
			}
			if (_ == 1){
				for (long long i = x;i < j;i ++ ){
					b[i] = 0;
				}
			}
			b.push_back(a[j]);
		}
		for (long long j = 0;j < m;j ++){
			_[b[j]] += 1;
		}
	}
	for (int i = 0;i < m;i ++ ){
		cout << _[i] << " ";
	}
	return 0;
}
