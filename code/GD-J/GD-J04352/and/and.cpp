#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	unsigned long long n,m,ans = 0;
	cin >> n >> m;
	vector<unsigned long long> v(n + 1);
	for(int i = 0;i<n;i++) cin >> v[i];
	if(m == 1){
		for(unsigned long long i = 0;i<n;i++){
			ans = max(ans,v[i]);
		}
	}
	if(m == 2){
		for(unsigned long long i = 0;i<n;i++){
			for(unsigned long long j = 0;j<n && j != i;j++){
				ans = max(ans,v[i] & v[j]);
			}
		}
	}
	if(m == n){
		for(unsigned long long i = 0;i<n;i++){
			if(i == 0) ans = v[i];
			else ans &= v[i];
		}
	}
	if(m == n - 1){
		for(unsigned long long i = 0;i<n;i++){
			unsigned long long t = 0;
			if(i == 0){
				for(unsigned long long j = 1;j<n;j++){
					if(j == 1) t = v[j];
					else t &= v[j];
				}
			}
			else{
				for(unsigned long long j = 0;j<n && j != i;j++){
					if(j == 0) t = v[j];
					else t &= v[j];
				}
			}
			ans = max(ans,t);
		}
	}
	cout << ans;
	
	return 0;
}
