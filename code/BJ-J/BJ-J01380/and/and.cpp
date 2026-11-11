#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m == 1){
		long long maxa = INT_MIN;
		for(int i = 1;i <= n;i++){
			if(maxa < a[i]) maxa = a[i];
		}
		cout << maxa;
	}else if(m == 2){
		int maxand = INT_MIN;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(maxand < (i & j)) maxand = (i & j);
			}
		}
		cout << maxand;
	}
	return 0;
}
