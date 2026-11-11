#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m;
long long a[N];
long long dp[N][2];
void dfs(int k){
	if(k>n){
		return;
	}
	for(int i = 1;i<=k;i++){
		if(dp[i][0]+1>m)continue;
		if(dp[k][1]<dp[i][1]&a[k]){
			dp[k][1] = dp[i][1]&a[k];
			dp[k][0] = dp[i][0]+1;
		}
	}
	dfs(k+1);
}
bool flag_b = true;
long long get_mi(int k){
	if(k==0)return 1;
	if(k==1)return 2;
	int d = get_mi(k/2);
	if(k%2==0)return d*d;
	else return d*d*2;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long f_1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		f_1 = max(f_1,a[i]);
		if(a[i]!=i-1)flag_b = false;
	}
	if(m==1){
		cout<<f_1;
		return 0;
	}
	if(m==2){
		long long ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					long long k = a[i]&a[j];
					ans = max(ans,k);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		long long ans = a[1];
		for(int i = 2;i<=n;i++){
			ans = ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		cout<<5;
		return 0;
	}
	if(flag_b){
		cout<<0;
		return 0;;
	}
	vector<int> v[50];
	for(int i = 1;i<=n;i++){
		int k = a[i];
		int cnt = 1;
		while(k){
			if(k&1)v[cnt].push_back(i);
			k>>=1;
			cnt++;
		}
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		if(v[i].size()>=m){
			ans+=get_mi(i-1);
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
