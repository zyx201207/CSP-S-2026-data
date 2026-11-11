#include<bits/stdc++.h>
using namespace std;
int a[500005],n,maxn=1,x,mx=0,p=0,is=1;
long long m,z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int k=a[2]-a[1];
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]){
			maxn++;
		}
		if(a[i+1]-a[i]==k){
			p++;
		}
	}
	if(p==n-1){
		cout<<n/k;
		return 0;
	}
	mx=maxn;
	if(maxn==n-1){
		cout<<n;
		return 0;
	}
	z=m;
	for(int i=a[1];i<=a[n];i++){
		int dp[n]={0};
		m=z;
		is=0;
		mx=0;
		for(int j=1;j<=n;j++){
			int h=max(a[j],i);
			int g=min(a[j],i);
			dp[j]=h-g;
		}
		sort(dp,dp+n+1); 
		is=1;
		while(m!=0){
			if(m-dp[is]<0){
				break;
			}
			if(dp[is]>0){
				m-=dp[is];
			}
			is++; 
			mx++;
		}
		maxn=max(maxn,mx);
	}
	cout<<maxn;
	return 0;
}
