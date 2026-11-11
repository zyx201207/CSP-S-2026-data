#include <bits/stdc++.h>
using namespace std;

long long a[500005],n,m,ans;

bool cmp(int A,int B){
	return A < B;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(long long i = 2;i <= n;i++){
		if(a[i] < 0){
			long long a1 = abs(a[i]),a2 = abs(a[i - 1]);
			if(a2 - a1 <= m){
				m -= (a2 - a1) * (i - 1);
				ans++;
				if(i == 2){
					ans++;
				}
			}
		}
		else if(a[i] - a[i - 1] <= m){
			m -= (a[i] - a[i - 1]) * (i - 1);
			ans++;
			if(i == 2){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
} 
