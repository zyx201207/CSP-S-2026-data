#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,f[1005],b[21][21],s[21],w[21],tot = 1,p[21];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 0){
		for(int i = 2;i <= n;i++){
			for(int j = 1;j < i;j++){
				if(a[i] == a[j])
					ans++;
			}
		}
		cout << ans;
		return 0;
	}
	else if(m > 1e9){
		long long cnt = -1e18;
		bool flag = 1;
		for(int i = 1;i <= n;i++){
			cnt += a[i];
			if(a[i] != i) flag = 0;
		} 
		if(n * cnt <= m){
			cout << n-1;
			return 0; 
		} 
		if(flag == 1){
			long long b = 0;
			for(int i = 1;b <= m;i++){
				ans++;
				b += i;
			}
			cout << ans;
			return 0;
		}
	}
	else if(m <= 1e9){
		long long cnt = -1e18;
		for(int i = 1;i <= n;i++){
			cnt = max(cnt,a[i]);
		} 
		if(n * cnt <= m){
			cout << n;
			return 0; 
		} 
	}
	if(n <= 16){
		memset(b,1e9,sizeof(b));
		memset(s,-1e9,sizeof(s));
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[i] >= a[j]) b[i][j] = a[i]-a[j];
				else if(a[i] < a[j]) b[i][j] = a[j]-a[i];
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				s[j] = b[i][j];
			}
			for(int k = 1;k <= n;k++){
				bool flag = 1;
				for(int j = k + 1;j <= n;j++){
					if(a[k] < a[j]) {
						swap(a[k],a[j]);
						flag = 0;
					}
				}
				if(flag == 1) break;
			}
			p[i] = 1;
			for(int i = m;i-s[i] >= 0;i -= s[i]){
				p[i]++;
			}
		}
		for(int i = 1;i <= n;i++){
			ans = max(ans,p[i]);
			cout << p[i] << " ";
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}
