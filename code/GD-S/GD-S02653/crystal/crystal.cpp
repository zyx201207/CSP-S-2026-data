#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,m,a[N],b[N],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = n;i >= 1;i--){
		for(int j = 1;j <= i;j++){
			b[j] = a[i] - a[j];
		}
		sort(b + 1,b + n);
		long long t1 = 0,t2 = 0;
		for(int j = 1;j <= i;j++) {
			if(t1 + b[j] <= m){
				t1 += b[j];
				t2++;
			}
		}
		maxn = max(maxn , t2);
	}
	cout << maxn;
	return 0;
}
