#include <bits/stdc++.h>

using namespace std;

int n;
unsigned long long m;
long long ca = -1LL;
int arr[60005];
int tarr[60005];
int cnt[60005];

int ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		cin >>arr[i];
		tarr[i] = arr[i];
		ca += arr[i];
	}

	
	sort(arr+1,arr+n+1);
	sort(tarr+1,tarr+n+1);


	unsigned long long tm = m;
	for(int i = ca; i> -1000 ;--i){
//		cout << i << "fff" << " ";
//		
//		cout << arr[i] << endl;

		m = tm;
		for(int j = i; j > 0; --j) {
			if(m==0) break;
			
			if(arr[i] >= ca){
				continue;
			}
			if(arr[i] < ca){
				if(m > ca-arr[i]){
					tarr[i] = ca;
					m = m - (ca-arr[i]);
				}
			}
		}
//		for(int j = 1;j<=n;++j) {
//			cout << tarr[j] ;
//		}
//		cout << endl;
		int temp = 2;
		sort(tarr+1,tarr+n+1);
		for(int j = 1; j <= n; ++j) {
			 
			if(tarr[j] == tarr[j-1]){
				temp++;
			}
			
			
		}
//		cout << temp << ' ';
		
		cnt[i] = temp;
		
	}
	
//	for(int i = 0; i < n; ++i ){
//		cout <<arr[i]<<' ';	
//	}
	int ans; 
	for(int i = 1; i <= n; ++i) {
		ans = max(cnt[i],cnt[i-1]);
	}
	cout << ans;
	
	return 0;
}
