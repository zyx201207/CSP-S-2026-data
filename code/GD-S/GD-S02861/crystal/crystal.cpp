#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10;
long long n,m,ans = -10;
long long a[N],b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(1 + a,1 + n + a);
	b[0] = 0;
	b[1] = a[1];
	for(int i = 2;i <= n;i++){
		b[i] = a[i] + b[i - 1];
//		cout << b[i] << " ";
	}
	
//	cout << "\n";
	
	for(long long i = n;i >= 2;i--){
		
		for(long long q,len,j = 0;j < i;j++){
			len = i - j;
			if(len <= ans) break;
//			cout << i << " " << j << "\n";
			q = a[i] * len - (b[i] - b[j]);
//			cout << "q " << q << "\n";
			
			if(q > m){
				continue;
			}
			ans = max(ans,len);
//			cout << ans << "\n";
		}
	}
	cout << ans;
}
