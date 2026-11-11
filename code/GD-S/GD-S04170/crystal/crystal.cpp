#include <bits/stdc++.h>
using namespace std;

int n,m;
int crl[500001];
int dp[100000001] = {0};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> crl[i];
	}
	for(int i  =1;i <= m;i++)dp[i] = 1;
	
	
	for(int i = 2;i <= n;i++){
		int ve = 0;
		int m1 = m;
		for(int j = 1;j < i;j++){
			int m1 = m;
			ve = crl[i] - crl[j];
			for(int k = m1;k >= 1;k--){
				if(k >= ve && ve >= 0 && m1 >= ve){
					dp[k] = max(dp[k],dp[k-ve] + 1);
					m1 -= ve;
				}
			}
		}
	}
	cout << dp[m];
	
	return 0;
} 
