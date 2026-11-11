#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,a[200005];
long long dp[200005];
//void fun(){
//	dp[1]=a[1];
//	for(int i=1;i<=n;i++){
//		//ГїТ»По
//		for(int j=m-1;j>=1;j--){
//			dp[i]=max(dp[i],dp[j]&a[i]);
//		}		 
//	}
//}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n+5;i++) dp[i]=0;
	for(int i=1;i<=n+5;i++) a[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//fun();
	//cout<<dp[n];
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[m];
	}
	cout<<sum;
	return 0;
} 

//4 2 3 15 12 12
// 5 3 31 3 1 15 7
