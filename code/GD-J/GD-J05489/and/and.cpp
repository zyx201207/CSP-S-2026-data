#include<iostream>
using namespace std;
long long a[200005],check[200005];
int main(){
	/*freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);*/
	long long n,m;
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	long long maxx = -1;
	long long U = (1 << n) - 1;
	for(long long i = 1;i <= U;i++){
		long long q = 0,sum = 0;
		bool f = 1;
		for(long long j = 0;j <= n;j++){
			long long k = 1 << j;
			long long z = i & k;
			if(z != 0){
				sum++;
				check[q] = a[j];
				q++;
			}
			if(sum > m){
				f = 0;
				break;
			}
		}
		if(!f)continue;
		long long ans = check[0];
		for(long long j = 1;j < m;j++){
			ans = ans & check[j];
		}
		maxx = max(maxx,ans);
	}
	cout << maxx << endl;
	return 0;
}
