#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=2e5+5;
int n,m;
ll a[M];
ll dp[M];
ll maxn;
ll sum;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	bool f=true;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1) sum=a[i];
		else sum&=a[i];
		
		if(a[i]!=i-1) f=false;
	}

	if(f==true){
		cout<<n-m;
	}else if(m==1){
		cout<<maxn;
	}else if(m==2 && n<=50000){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else if(m==n){
		cout<<sum;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				dp[j]=max(dp[j],(dp[j-1] & a[i]));
			}
			dp[1]=max(dp[1],a[i]);	
		}
	
		cout<<dp[m];	
	}
	

	
	return 0;
}

