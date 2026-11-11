#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long n, d;
vector<long long> ans;
void dfs(long long s, long long e, long long l){
	if(s == e){
		ans.push_back(l);
		return;
	}
	if(s + 3 <= n && a[s + 3] - a[s] <= d)
		return;
	for(long long i = s + 1;i <= s + 2 && i <= n;i++){
		if(a[i] - a[s] > d) break;
		dfs(i, e, l + 1);
	}
	return;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	if(c >= 1 && c <= 2){
		while(t--){
			long long o = 0;
			cin >> n >> d;
			for(long long i = 1;i <= n;i++)
				cin >> a[i];
			for(long long i = 1;i <= n;i++){
				for(long long j = i + 3;j <= n;j++){
					ans.clear();
					dfs(i, j, 0);
					long long minn = LLONG_MAX, mincnt = 0;
					for(auto it = ans.begin();it != ans.end();it++){
						if(*it < minn){
							minn = *it;
							mincnt = 1;
						}
						else if(*it == minn){
							mincnt++;
						}
					}
					if(mincnt == 2) o++;
				}
			}
			cout << o << '\n';
		}
		return 0;
	}
	long long ans_ = 0;
	while(t--){
		ans_ = 0;
		long long n, d;
		cin >> n >> d;
		for(long long i = 1;i <= n;i++)
			cin >> a[i];
		for(long long i = 1;i <= n;i++){
			if(a[i + 3] - a[i] > d && a[i + 3] - a[i + 1] <= d && a[i + 1] - a[i] <= d && a[i + 3] - a[i + 2] <= d && a[i + 2] - a[i] <= d){
				long long l = 1, r = 1;
				long long i_;
				if(i == 1) l = 1;
				else{
					i_ = i;
					while(i_ > 1 && a[i_] - a[i_ - 1] <= d && a[i_ + 1] - a[i_ - 1] > d){
						i_--;
						l++;
					}
				}
				if(i + 3 == n) r = 1;
				else{
					i_ = i + 3;
					while(i_ < n && a[i_ + 1] - a[i_] <= d && a[i_ + 1] - a[i_ - 1] > d){
						i_++;
						r++;
					}
				}
				ans_ += l * r;
			}
		}
		cout << ans_ << '\n';
	}
	return 0;
}
