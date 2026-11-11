#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5; // m <= 1e18 abs(ai) <= 1e12
const ll INF = 1e18;
ll a[N],dp[N],n,m,mn[N],dengcha,maxx = 0;
void solve1(){
	dp[0] = 0,dp[1] = 0;
	for(int i = 2;i <= n;i++){
		ll de = a[i] - a[i-1];
		for(int len = i;len > 0;len--){
			ll cha = (len-1) * de;
			dp[len] = cha + dp[len-1];  
			mn[len] = min(mn[len],dp[len]);
		}
	}
	for(int i = n;i >= 1;i--){
		if(mn[i] <= m){
			cout << i << endl;
			return ;
		}
	}
}
void solve2(){
	int len = 0;
	ll sum = 0;
	while(sum <= m && len < n){
		len++;
		sum += len * dengcha; 
	}
	cout << len;
	return;
}
void solve3(){
	int tong[205] = {0};//-100-100 -> 0-200
	for(int i = 1;i <= n;i++)
		tong[a[i]+100]++;
	int maxlen = 0;
	for(int i = 0;i <= 200;i++){
		if(!tong[i]) continue;
		int len = tong[i];
		ll sum = 0;
		for(int j = i-1;j >= 0;j--){
			if(!tong[j]) continue;
			if(sum + tong[j]*(i-j) > m){
				len += ((m-sum) / (i-j));
				break;
			}else{
				sum += tong[j]*(i-j);
				len += tong[j];
			}
		}
		maxlen = max(maxlen,len);
	}
	cout << maxlen; 
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	bool isdengcha = 1;
	cin >> n >> m;
	cin >> a[1]; 
	maxx = max(maxx,abs(a[1]));
	if(n >= 2){
		cin >> a[2];
		maxx = max(maxx,abs(a[2]));
		dengcha = a[2] - a[1];
	} 
	for(int i = 3;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,abs(a[i]));
		if(a[i] - a[i-1] != dengcha){
			isdengcha = 0;
		}
	}
	for(int i = 1;i <= n;i++)
		mn[i] = INF;
	sort(a+1,a+n+1);
	if(n <= 5000){
		solve1();
		return 0;
	} 
	if(isdengcha){
		solve2();
		return 0;
	}
	if(maxx <= 100){
		solve3();
		return 0;
	}
	solve1();
	return 0;
}
// 10 15 1 2 3 4 5 6 7 8 9 10
// 5 10 1 4 7 10 13
// 5 999 1 2 3 4 5
// 10 8 1 1 1 2 2 2 3 3 5 5
