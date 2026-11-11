#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	vector<int> index(m);
	for (long long i = 0;i < m;i++){
		index[i] = i;
	}
//	for (long long i = 0;i < m;i++)cout << index[i] << ' ';
	
	long long best_sum = 0;
	while (index[0] != n - m){
		long long sum = a[index[0]];
		for (long long i = 1;i < m;i++){
			sum &= a[index[i]];
		}
		if (sum > best_sum)best_sum = sum;
		
//		for (long long i = 0;i < m;i++)cout << index[i] << ' ';
//		cout << endl;
		long long i = m - 1;
		while (index[i] == n - (m - 1 - i))i--;
		index[i]++;
		for (;i < m;i++){
			index[i + 1] = index[i] + 1;
		}
	}
	cout << best_sum << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
