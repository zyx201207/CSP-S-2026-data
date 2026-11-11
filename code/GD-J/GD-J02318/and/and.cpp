#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
int n,m;
long long x[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	
	for(int i=1;i <= n;i ++) cin >> x[i];
	
	long long mx = -1e9;
	for(int i=1;i <= n;i ++){
		int m2 = m - 1;
		long long mx2 = -1e9;
		while(m2 != 0){
			int res = (i + (m - m2));
			
			for(int j=res;j <= n;j ++){
				mx2 = max(x[j] & x[i],mx2);
			}
			
			x[i] = mx2;
			m2 --;
		}
		mx = max(mx,mx2);
	}
	cout << mx;
	
	return 0;
}
