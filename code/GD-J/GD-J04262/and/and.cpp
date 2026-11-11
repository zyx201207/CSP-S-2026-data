#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
long long dp[N];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,maxn=0,maxx=0;int is_1=0,is_2=0;long long sum=0;
	cin>>n>>m;
	if(m==n){
		is_1=1;
	}
	if(m==1){
		is_2=1;
	}
	
	for(int i=1;i<=n;i++){
		cin>>dp[i];
		if(is_1==1){
			sum=sum&dp[i];
		}
		else if(is_2==1){
			maxn=max(maxn,dp[i]);
			sum=maxn;
		}
	}
	
	if(is_1==1 || is_2==1){
		cout<<sum;
		return 0;
	}

	m--;
	while(m--){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=dp[i] & dp[j];
				if(x>maxx){
					maxx=x;
				}
				dp[i]=maxx;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i]);
		sum=maxn;
	}

	cout<<sum;

	return 0;
}
