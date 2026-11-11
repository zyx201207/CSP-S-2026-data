#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,k;
int a[N];
int ans=0;
int dp[20005][20005]={0};

int dfs(int m,int cnt,int step){
	if(dp[m][step]!=0) return dp[m][step];
	if(m==k){
		return cnt;
	}
	if(step>n){
		return 0;
	}
	int ans=0;
	for(int i=step+1;i<=n;i++){
		ans=max(ans,dfs(m+1,cnt&a[i],i));;
	}
	return dp[m][step]=ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0xffffffff,0);
	return 0;
}

