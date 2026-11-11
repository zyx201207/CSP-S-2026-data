#include<bits/stdc++.h>
using namespace std;
int a[20099]={};
int dp[2099][20099];
int n,m;
bool b[2099][20099];
int f(int o,int k,int pq){
	int max_=-1,l_=-1;
	for(int i=1;i<k;i++){
		if(b[o][i])continue;
		if(a[i]&pq>max_){
			max_=a[i]&pq;
			l_=i;
		}
	}b[o][l_]=1;
	return max_;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[2][2]=a[1]&a[2];
	for(int j=3;j<=n;j++){
		dp[2][j]=max(f(2,j,a[j]),dp[2][j-1]);
	}
	for(int i=3;i<=m;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=max(f(i,j,dp[i-1][j]),dp[i][j-1]);
		}
	}
	cout<<dp[m][n];
	return 0;
}

