#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long a[200000];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a, a + n);
		cout << a[n - 1];
	}else{
		if(n = 2){
			bool p[23], q[23];
			long long r, t;
			r = a[0];
			t = a[1];
			long long cnt = 0;
			while(r > 1){
				p[cnt] = bool(r%2);
				r/=2;
				cnt++;
			}
			p[cnt] = r;
			r = cnt+1;
			cnt = 0;
			while(t > 1){
				q[cnt] = bool(t%2);
				t/=2;
				cnt++;
			}
			q[cnt] = t;
			t = cnt+1;
			bool ans[23];
			for(int i = 0;i < min(r, t);i++){
				ans[i] = p[i] && q[i];
			}
			long long las = 0;
			for(int i = 0;i < min(r, t);i++){
				long long f = 1;
				for(int j = 0;j < i;j++){
					f *= 2;
				}
				if(ans[i]){
					las += f;
				}
			}
			cout << las;
		}else{
			cout << a[n/2];
		}
	}
	return 0;
}
