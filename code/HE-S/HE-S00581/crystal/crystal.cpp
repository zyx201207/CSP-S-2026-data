#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = 1;
long long a[500010];
long long dp[500010];//dp[i] = a[i+1]-a[i]
bool flag = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=a[i-1]&&i!=1) flag = 0;
	}
	if(flag){
		cout <<n;
		return 0;
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i = 1;i<=n;i++) dp[i] = a[i+1]-a[i];
		dp[n] = 0;
		int cnt = 0;
		int p = 0;
		for(int i = 1;i<=n;i++){
			int cha = dp[i];
			while(p<=m){
				cnt++;
				p+=cnt*cha;
				if(cnt==i) break;
			}
			
		}
		cout <<cnt;
	}else{
		int cnt = 0;
		int cha = a[2]-a[1];
		int p = 0;
		while(p<=m){
			cnt++;
			if(cnt>n){
				cout <<cnt-1;
				return 0;
			}
			p+=cha*cnt;
		}
		cout <<cnt;
	}
		
}

