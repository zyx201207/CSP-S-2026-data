#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e5+5;
int pdp[M],ndp[M],n,m,a[N],aand[N],mx[N];//dp[n][m],前n个数中选m个数的and值最大 ,mx[n]，前n个数中的最大值,pdp=dp[i-1],ndp=dp[i] 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aand[1]=a[1];
		mx[1]=a[1];
		if(i>=2){
			aand[i]=(aand[i-1]&a[i]);
			mx[i]=max(mx[i-1],a[i]);
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==j) ndp[j]=aand[i];
		}
	}
	for(int i=1;i<=n;i++){
		ndp[1]=mx[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,i);j++){
			if(i==j || j==1) continue;
			ndp[j]=max(pdp[j],pdp[j-1]&a[i]);
		}
		for(int j=1;j<=min(m,i);j++){
			pdp[j]=ndp[j];
		}
	}
	cout<<pdp[m];
	return 0;
} 
