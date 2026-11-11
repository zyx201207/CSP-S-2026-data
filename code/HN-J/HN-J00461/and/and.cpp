#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000000];
//int dp[2100000];
int ans,sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		dp[i]=a[i];
	}
	sort(a+1,a+1+n,cmp);	
	for(int j=1;j<=n;j++){
		ans=a[j];
		for(int w=0;w<m;w++){
			ans=ans&a[j+w];
		}
		sum=max(ans,sum);
	}
	cout<<sum;
	return 0;
} 
	
//	for(int w=1;w<m;w++){
//		for(int j=1;j<=n;j++){
//			dp[j]=max(dp[j]&a[j],dp[j-1]&a[j]);
//		}
//	}	
//	cout<<dp[n];


