#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int>s;
	int n,m;
	cin >> n >> m;
	int a;
	
	for(int i=0; i<n; i++){
		cin >> a;
		s.push_back(a);
	}
	int l=s.size();
	sort(s.begin(), s.end());
	//vector<vector<int> >dp(n,vector<int>(m,0));
	int dp[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(j>i) break;
			if(j==0){
				dp[i][j] = s[i];
			}else{
				dp[i][j] =0;
			}
			
		}
	}
	
	/*for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << dp[i][j] << ' ';
		}cout << '\n';
	}*/
	
	for(int i=1; i<n; i++){ // 前i+1个数 
		for(int j=1; j<m; j++){ //选j+1个数 
			if(j>i) break;
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] & s[i]);
		}
	}
	
	//cout << n << m << '\n';
	
	
	cout << dp[n-1][m-1];
	return 0;
}
