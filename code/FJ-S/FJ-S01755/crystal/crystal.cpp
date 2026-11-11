#include<bits/stdc++.h>

using namespace std;

const int maxn = 500050;
int a[maxn];
int sum[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	long long m;
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	bool ok = true;
	int sub = a[2] - a[1];
	for(int i = 3;i <= n;i++){
		if(a[i] - a[i - 1] != sub){
			ok = false;
			break;
		}
	}
	if(ok){
		long long s = 0;
		for(int i = 1;i <= n;i++){
			s += i * sub;
			if(s > m){
				cout << i;
				return 0;
			}
		}
	}
	
	sort(a+1,a+n+1);
	
	for(int i = 2;i <= n;i++){
		sum[i] = a[i] - a[i-1];
	}
	int ans = 0;
	for(int i = 2;i <= n;i++){
		long long num = 0;
		for(int j = i;j >= 2;j--){
			num += (j - 1) * sum[j];
			if(num <= m){
				ans = max(ans,i - j + 2);
			} else {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}