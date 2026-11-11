#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],dp[N],maxn=0;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	dp[1]=maxn;
	m+=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
