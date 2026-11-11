#include<bits/stdc++.h>
using namespace std;
const int x=500010;
long long n,m,a[x];

bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int maxn=-1,maxm;
	a[0]=0;
	for(int i=1;i<=n;i++){
		long long dp[x];
		for(int j=1;j<=n;j++){
			dp[j]=dp[j-1]+a[j];
			if((dp[j]+m)/j==a[j]){
				maxn=max(maxn,j);
			}
		}
	}
	maxn=max(maxn,maxm);
	cout<<maxn;
	return 0; 
}
