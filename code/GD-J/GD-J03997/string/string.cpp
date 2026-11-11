#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
long long a[maxn];
char c[maxn];
int main(){
//	ios::sync__stdio(0);
//	cin.tie(0), cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long len = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	long long mid_len = len/2;
	if(len & 1){
		long long l = 0;
		for(int i = 1;i <= n;i++){
			l += a[i];
			if(l > mid_len){
				a[i]--;
				break;
			}
		}
		len--;
	}
	vector<pair<long long,char>> L, R;
	long long sum = 0;
	bool flag = 0;
	for(int i = 1;i <= n;i++){
		sum += a[i];
		if(flag){
			if(R.size() && R[R.size()-1].second == c[i]){
				R[R.size()-1].first += a[i];
			}else{
				R.push_back({a[i],c[i]});
			}
		}else if(sum > mid_len){
			if(a[i] - (sum-mid_len) > 0){
				if(L.size() && L[L.size()-1].second == c[i]){
					L[L.size()-1].first += a[i] - (sum-mid_len);
				}else{
					L.push_back({a[i] - (sum-mid_len),c[i]});
				}
			}
			if(R.size() && R[R.size()-1].second == c[i]){
				R[R.size()-1].first += sum-mid_len;
			}else{
				R.push_back({sum-mid_len,c[i]});
			}
			flag = 1;
		}else{
			if(L.size() && L[L.size()-1].second == c[i]){
				L[L.size()-1].first += a[i];
			}else{
				L.push_back({a[i],c[i]});
			}
		}
	}
	reverse(R.begin(),R.end());
	
	long long l = 0, r = 0;
	long long ans = 0;
	while(1){
		if(L[l].first == 0){
			l++;
			if(l >= L.size()){
				break;
			}
		}
		if(R[r].first == 0){
			r++;
			if(r >= R.size()){
				break;
			}
		}
		if(L[l].first == R[r].first){
			if(L[l].second == R[r].second){
				L[l].first = 0, R[r].first = 0;
			}else{
				ans += L[l].first;
				L[l].first = 0, R[r].first = 0;
			}
		}else if(L[l].first > R[r].first){
			if(L[l].second == R[r].second){
				L[l].first = L[l].first - R[r].first, R[r].first = 0;
			}else{
				ans += R[r].first;
				L[l].first = L[l].first - R[r].first, R[r].first = 0;
			}
		}else{
			if(L[l].second == R[r].second){
				R[r].first = R[r].first - L[l].first, L[l].first = 0;
			}else{
				ans += L[l].first;
				R[r].first = R[r].first - L[l].first, L[l].first = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
