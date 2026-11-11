#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5;
int dp[2005][2005];
int a[N];
int cnt[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool C=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(C)
			cnt[a[i]]++;
		if(a[i]>4)C=0;
	}
	if(C){
		m-=cnt[3];
		if(m<=0)cout<<3;
		else{
			m-=cnt[2];
			if(m<=0)cout<<2;
			else cout<<0; 
		}
		return 0;
	}
	if(n<=2000){
		for(int i=0;i<=n;i++){
			dp[0][i]=0xffffffff;
		}
		for(int i=1;i<=m;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=max(dp[i][j-1],(dp[i-1][j-1]&a[j]));
			}
		}
		cout<<dp[m][n];
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<a[m];
	return 0;
} 
